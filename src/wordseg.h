//
// Created by Xu,Ming(RCPT) on 17/7/28.
//

#ifndef CPP_TUTORIAL_WORDSEG_H
#define CPP_TUTORIAL_WORDSEG_H


#include <string>

namespace asl {

class WordSeg {
public :
    WordSeg();

    ~WordSeg();

    /**
     * init
     * @param dict_path
     * @param seg_buf_size
     * @return
     */
    bool init(const std::string &dict_path, uint32_t seg_buf_size);

    bool get_segment_words(const std::string &str, std::string *out_str, uint32_t *word_cnt);

    bool get_segment_words_mix(const std::string &str, std::string *out_str, uint32_t *word_cnt);

    bool get_segment_words(const std::string &str, std::string *out_str,
                           std::string *out_str_2, uint32_t *word_cnt);

    scw_out_t *get_scw_out();

    scw_worddict_t *get_seg_dict() const;

private:
    pthread_mutex_t _lock;
    scw_worddict_t *_pwdict;
    uint32_t _seg_buf_size;
    std::map<pthread_t, scw_out_t *> _handle_map;

};
};

#endif //CPP_TUTORIAL_WORDSEG_H
