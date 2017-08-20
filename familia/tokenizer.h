//
// Created by Xu,Ming(RCPT) on 17/8/18.
//

#ifndef CPP_TUTORIAL_TOKENIZER_H
#define CPP_TUTORIAL_TOKENIZER_H

#include "algorithm"
#include <fstream>
#include <string>
#include <unordered_set>

#include "util.h"

namespace familia {
    class Tokenizer {
    public:
        Tokenizer() = default;
        virtual ~Tokenizer() = default;
        virtual void tokenize(const std::string& text,std::vector<std::string>& result) const = 0;
    };

    class SimpleTokenizer: public Tokenizer{
    public:
        SimpleTokenizer(const std::string& vocab_path): _max_word_len(1){
            load_vocab(vocab_path);
        }

        ~SimpleTokenizer() = default;

        void tokenize(const std::string& text,std::vector<std::string>& result)const override ;

        bool contains(const std::string& word) const;

    private:
        void load_vocab(const std::string& vocab_path);

        static bool is_eng_char(char c){
            return (c>='A' && c<='Z')||(c>='a'&&c<='z');
        }
        static char tolower(char c){
            if (c>='A' && c<='Z'){
                return 'a'+(c-'A');
            }else{
                return c;
            }
        }
        int _max_word_len;
        std::unordered_set<std::string> _vocab;
    };
} // namespace familia
#endif //CPP_TUTORIAL_TOKENIZER_H
