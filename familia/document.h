//
// Created by Xu,Ming(RCPT) on 17/8/18.
//

#ifndef CPP_TUTORIAL_DOCUMENT_H
#define CPP_TUTORIAL_DOCUMENT_H

#include <algorithm>
#include <string>
#include <vector>

namespace familia {
    // topic struct
    struct Topic {
        int tid; // topic id
        double prob; // topic probability
        bool operator<(const Topic &t) const {
            return prob > t.prob;
        }
    };

    // LAD document store unit
    struct Token {
        int topic; // topic id
        int id;    // word id
    };

    // SentenceLAD document store unit
    struct Sentence {
        int topic; // topic id
        std::vector<int> tokens; // document ids
    };

    // LDA model inference store struct
    class LDADoc {
    public:
        LDADoc() = default;

        explicit LDADoc(int num_topics) {
            init(num_topics);
        }

        void init(int num_topics);

        void add_token(const Token &token);

        inline Token &token(size_t index) {
            return _tokens[index];
        }

        void set_topic(int index, int new_topic);

        // set document param: alpha
        inline void set_alpha(float alpha) {
            _alpha = alpha;
        }

        // word num of document
        inline size_t size() const {
            return _tokens.size();
        }

        inline size_t topic_sum(int topic_id) const {
            return _topic_sum[topic_id];
        }

        // get sparse document topic distribution, ignore alpha
        void sparse_topic_dist(std::vector<Topic> &topic_dist, bool sort = true) const;

        // get dense document topic distribution, use alpha
        void dense_topic_dist(std::vector<float> &dense_dist) const;

        // Accmulate every round of sample result
        void accumulate_topic_sum();


    protected:
        int _num_topics; // topic number
        int _num_accum; // accumulate LDA round number
        float _alpha; // document alpha
        std::vector<Token> _tokens; // inference store struct
        std::vector<int> _topic_sum; // one round topic sum result
        std::vector<int> _accum_topic_sum; // topic sum result
    };

} // namespace familia
#endif //CPP_TUTORIAL_DOCUMENT_H
