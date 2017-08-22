//
// Created by Xu,Ming(RCPT) on 17/8/22.
//

#ifndef CPP_TUTORIAL_VOCAB_H
#define CPP_TUTORIAL_VOCAB_H

#include <iostream>
#include <string>
#include <unordered_map>

namespace familia {
    constexpr int OOV = -1;

    class Vocab {
    public:
        Vocab() = default;

        int get_id(const std::string &word) const;

        void load(const std::string &vocab_file);

        size_t size() const;

        Vocab(const Vocab &) = delete;

        Vocab &operator=(const Vocab &) = delete;

    private:
        std::unordered_map<std::string, int> _term2id;
    };
} // namespace familia
#endif //CPP_TUTORIAL_VOCAB_H
