//
// Created by Xu,Ming(RCPT) on 17/8/22.
//

#ifndef CPP_TUTORIAL_VOSE_ALIAS_H
#define CPP_TUTORIAL_VOSE_ALIAS_H

#include "util.h"
#include <vector>

namespace familia {
    class VoseAlias {
    public:
        VoseAlias() = default;

        void init(const std::vector<double> &dist);

        // Generating a sampling sample from a given distribution
        int generate() const;

        // Dimension of discrete distribution
        inline size_t size() const {
            return _prob.size();
        }

        VoseAlias(const VoseAlias &) = delete;

        VoseAlias &operator=(const VoseAlias)= delete;

    private:
        std::vector<int> _alias; // alias table
        std::vector<double> _prob; // probability table
    };
} // namespace familia
#endif //CPP_TUTORIAL_VOSE_ALIAS_H
