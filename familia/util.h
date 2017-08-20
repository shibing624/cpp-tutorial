//
// Created by Xu,Ming(RCPT) on 17/8/18.
//

#ifndef CPP_TUTORIAL_UTIL_H
#define CPP_TUTORIAL_UTIL_H

#include "atomic"
#include "ctime"
#include "random"
#include "string"
#include "fstream"
#include "sstream"
#include <glog/logging.h>
#include <google/protobuf/text_format.h>

namespace familia {
    // get random seed in multi processes
    inline std::default_random_engine &local_random_engine() {
        struct engine_wrapper_t {
            std::default_random_engine engine;

            engine_wrapper_t() {
                static std::atomic<unsigned long> x(0);
                std::seed_seq seq = {x++, x++, x++, x++};
                engine.seed(seq);
            }
        };
        static engine_wrapper_t r;
        return r.engine;
    }

    inline void fix_random_seed(int seed = 2147483647) {
        auto &engine = local_random_engine();
        engine.seed(seed);
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);
        distribution.reset(); // reset sample
    }

    // split with sep
    void split(std::vector<std::string> &result, const std::string &text, char sep);
} // namespace familia
#endif //CPP_TUTORIAL_UTIL_H
