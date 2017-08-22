//
// Created by Xu,Ming(RCPT) on 17/8/18.
//

#include "document.h"
#include "util.h"

namespace familia {
    void LDADoc::init(int num_topics) {
        _num_topics = num_topics;
        _num_accum = 0; // init is zero
        _tokens.clear();
        _topic_sum.resize(_num_topics, 0);
        _accum_topic_sum.resize(_num_topics, 0);
    }

    void LDADoc::add_token(const Token &token) {
        CHECK_GE(token.topic, 0) << "Topic " << token.topic << " out of range!";
        CHECK_LT(token.topic, _num_topics) << "Topic " << token.topic << " out of range.";
        _tokens.push_back(token);
        _topic_sum[token.topic]++;
    }

    void LDADoc::set_topic(int index, int new_topic) {
        CHECK_GE(new_topic, 0) << "Topic " << new_topic << " out of range.";
        CHECK_LT(new_topic, _num_topics) << "Topic " << new_topic << " out of range.";
        int old_topic = _tokens[index].topic;
        if (new_topic == old_topic) {
            return;
        }
        _tokens[index].topic = new_topic;
        _topic_sum[old_topic]--;
        _topic_sum[new_topic]++;
    }

    void LDADoc::sparse_topic_dist(std::vector<Topic> &topic_dist, bool sort) const {
        topic_dist.clear();
        size_t sum = 0;
        for (int i = 0; i < _num_topics; ++i) {
            sum += _accum_topic_sum[i];
        }

        if (sum == 0) {
            return;
        }
        for (int i = 0; i < _num_topics; ++i) {
            if (_accum_topic_sum[i] == 0) {
                continue;
            }
            topic_dist.push_back({i, _accum_topic_sum[i] * 1.0 / sum});
        }
        if (sort) {
            std::sort(topic_dist.begin(), topic_dist.end());
        }
    }

    void LDADoc::dense_topic_dist(std::vector<float> &dense_dist) const {
        dense_dist.clear();
        dense_dist.resize(_num_topics, 0.0);
        if (size() == 0) {
            return;
        }
        for (int i = 0; i < _num_topics; ++i) {
            dense_dist[i] = (_accum_topic_sum[i] * 1.0 / _num_accum + _alpha)
                            / (size() + _alpha * _num_topics);
        }
    }

    void LDADoc::accumulate_topic_sum() {
        for (int i = 0; i < _num_topics; ++i) {
            _accum_topic_sum[i] += _topic_sum[i];
        }
        _num_accum += 1;
    }

}