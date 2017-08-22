//
// Created by Xu,Ming(RCPT) on 17/8/22.
//

#ifndef CPP_TUTORIAL_MODEL_H
#define CPP_TUTORIAL_MODEL_H

#include "config.pb.h"
#include "util.h"
#include "vocab.h"

#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <limits>

namespace familia {
    // topic pair: key:topic id; value:count
    typedef std::pair<int, int> TopicCount;
    // topic distribution: form by TopicCount
    typedef std::vector<TopicCount> TopicDist;

    class TopicModel {
    public:
        TopicModel() = delete;

        TopicModel(const std::string &model_dir, const ModelConfig &config);

        inline int term_id(const std::string &term) const {
            return _vocab.get_id(term);
        }

        void load_model(const std::string &word_topic_path,const std::string &vocab_path);


    private:
        void load_word_topic(const std::string &word_topic_path);

        std::vector<TopicDist> _word_topic; // word topic param
        std::vector<uint64_t> _topic_sum; // one dimension topic count
        Vocab _vocab; // topic model vocab struct
        int _num_topics; // topic number
        float _alpha;
        float _alpha_sum;
        float _beta;
        float _beta_sum;
        ModelType _type; // model type
    };
} // namespace familia
#endif //CPP_TUTORIAL_MODEL_H
