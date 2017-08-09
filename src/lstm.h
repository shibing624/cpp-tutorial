//
// Created by Xu,Ming(RCPT) on 17/7/28.
//

#ifndef CPP_TUTORIAL_LSTM_H
#define CPP_TUTORIAL_LSTM_H

#include <map>
#include <set>
#include "wordseg.h"

namespace lstm {
    class ModelPredict {
    public:
        ModelPredict();

        explicit ModelPredict(asl::WordSeg *wordseg);

        ~ModelPredict();

        bool read_dict(const std::string &file);

        bool is_contain_design(const std::string &text, std::string *sense_word);

        bool read_vocab(const std::string &vocab_path);

        bool load_from_file(const std::string &file);

        bool exe_sys(const char *cmd_line);

        void gen_instance(
                const std::string &text_seg,
                paddle_platform::SparseNonValueInstance &ins,
                std::map<std::string, uint32_t> &word_map
        );

        float predict(const std::string& text);
        bool wordseg_init(asl::WordSeg* wordseg);

    private:
        void clear_data();

        std::set<std::string> _filterlist;

        std::map<std::string,uint32_t> _word_map;


    };

}


#endif //CPP_TUTORIAL_LSTM_H
