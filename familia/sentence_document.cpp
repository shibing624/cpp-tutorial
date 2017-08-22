//
// Created by Xu,Ming(RCPT) on 17/8/22.
//

#include "sentence_document.h"
#include "util.h"

namespace familia {
    void SLDADoc::init(int num_topics) {
        _num_topics = num_topics;
        _sentences.clear();
        _topic_sum.resize(_num_topics, 0);
        _accum_topic_sum.resize(_num_topics, 0);
    }

    void SLDADoc::add_sentence(const Sentence &sent) {
        CHECK_GE(sent.topic, 0) << "Topic " << sent.topic << " out of range!";
        CHECK_LT(sent.topic, _num_topics) << "Topic " << sent.topic << " out of range!";
        _sentences.push_back(sent);
        _topic_sum[sent.topic]++;
    }

    void SLDADoc::set_topic(int index, int new_topic) {
        CHECK_GE(new_topic, 0) << "Topic " << new_topic << " out of range.";
        CHECK_LT(new_topic, _num_topics) << "Topic " << new_topic << " out of range.";
        int old_topic = _sentences[index].topic;
        if (new_topic == old_topic) {
            return;
        }
        _sentences[index].topic = new_topic;
        _topic_sum[old_topic]--;
        _topic_sum[new_topic]++;
    }
} // namespace familia
