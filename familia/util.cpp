//
// Created by Xu,Ming(RCPT) on 17/8/18.
//

#include "util.h"

namespace familia {

    void split(std::vector<std::string> &result, const std::string &text, char sep) {
        size_t start = 0;
        size_t end = 0;
        if (text.empty()) {
            return;
        }
        while ((end = text.find(sep, start)) != std::string::npos) {
            std::string subStr = text.substr(start, end - start);
            result.push_back(std::move(subStr));
            start = end + 1;
        }
        result.push_back(text.substr(start)); // get original text
    }
} // namespace familia