//
// Created by Xu,Ming(RCPT) on 17/8/18.
//

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>

namespace familia {

    void SimpleTokenizer::tokenize(const std::string &text, std::vector<std::string> &result) const {
        result.clear();
        std::string word;
        std::string found_word;
        int text_len = text.size();
        for (int i = 0; i < text_len; ++i) {
            word.clear();
            found_word = "";
            if (is_eng_char(text[i])) {
                for (int j = i; i <= text_len; ++j) {
                    if (j < text_len && is_eng_char(text[j])) {
                        word.push_back(tolower(text[j]));
                    } else {
                        if (_vocab.find(word) != _vocab.end()) {
                            result.push_back(word);
                        }
                        i = j - 1;
                        break;
                    }
                }
            } else {
                for (int j = i; j < i + _max_word_len && j < text_len; ++j) {
                    word.push_back(text[j]);
                    if (_vocab.find(word) != _vocab.end()) {
                        found_word = word;
                    }
                }
                if (found_word.size() > 0) {
                    result.push_back(found_word);
                    i += found_word.size() - 1;
                }
            }
        }
    }

    bool SimpleTokenizer::contains(const std::string &word) const {
        return _vocab.find(word) != _vocab.end();
    }

    void SimpleTokenizer::load_vocab(const std::string &vocab_path) {
        LOG(INFO) << "Loading vocabulary file from: " << vocab_path;
    }
}// namespace familia
