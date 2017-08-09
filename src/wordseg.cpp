//
// Created by Xu,Ming(RCPT) on 17/7/28.
//

#include "wordseg.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <map>
#include <pthread.h>
#include <bsm/audit.h>
#include <vector>

namespace asl {

    using std::string;

    WordSeg::WordSeg() : _pwdict(NULL), _seg_buf_size(0) {
        pthread_mute_init(&_lock, NULL);
    }

    WordSeg::~WordSeg() {
        std::map<pthread_t, scw_out_t *>::iterator it = _handle_map.begin();
        for (; it != _handle_map.end(); ++it) {
            if (it->second != NULL) {
                scw_destory_out(it->second);
                it->second = NULL;
            }
        }

        if (_pwdict != NULL) {
            scw_destroy_worddict(_pwdict);
            _pwdict = NULL;
        }
        pthread_mutex_destroy(&_lock);
    }

    bool WordSeg::init(const std::string &dict_path, uint32_t seg_buf_size) {
        bool ret = false;
        pthread_mutex_lock(&_lock);
        do{
            if(_pwdict!=NULL){
                ret = true;
                break;
            }
            _seg_buf_size = seg_buf_size;
            if((_pwdict = scw_load_worddict(dict_path.c_str()))==NULL){
                ASL_FATAL_LOG("Load worddict failed.Filename=%s\n",dict_path.c_str());
                break;
            }
            ASL_NOTICE_LOG("Load worddict success.Filename=%s\n",dict_path.c_str());
            ret = true;
        }while (0);
        pthread_mutex_unlock(&_lock);
        return ret;
    }

    bool WordSeg::get_segment_words(const std::string &str, std::string *out_str, uint32_t *word_cnt) {
        scw_out_t* result = get_scw_out();
        if(result == NULL){
            return false;
        }

        out_str->assign(result->wordsegbuf);
        *word_cnt = result->wsbtermcount;
        return true;
    }

    bool WordSeg::get_segment_words(const std::string &str, std::string *out_str, std::string *out_str_2,
                                    uint32_t *word_cnt) {
        scw_out_t* result = get_scw_out();
        if(result == NULL){
            return false;
        }
        if(scw_segment_words(get_seg_dict(),result,str.c_str(),str.size(),LANGTYPE_SIMP_CHINESE,NULL)==-1){
            return false;
        }
        token_t tokens[10240];
        string tmp_str = "";
        std::vector<std::string> wpcomp_vec;
        u_int count = scw_get_token_1(result,SCW_OUT_WPCOMP,tokens,10240);
        for(u_int index = 0;index<count;index++){
            tmp_str = tokens[index].buffer;
            if(!boost::trim_copy(tmp_str).empty() && tmp_str! = "\t"){
                wpcomp_str+= tokens[index].buffer;
                wpcomp_str += " ";
            }
        }
        out_str_2 -> assign(wpcomp_str);
        out_str->assign(result->wordsegbuf);
        *word_cnt = result->wsbtermcount;
        return true;
    }
}