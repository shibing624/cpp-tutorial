//
// Created by Xu,Ming(RCPT) on 17/8/22.
//

#ifndef CPP_TUTORIAL_SENTENCE_DOCUMENT_H
#define CPP_TUTORIAL_SENTENCE_DOCUMENT_H

#include "document.h"

namespace familia {
    // Sentence LDA Documnet
    // extended by LDADoc, add one: add_sentence
    class SLDADoc : public LDADoc {
    public :
        SLDADoc() = default;

        void init(int num_topics);

        void add_sentence(const Sentence &sent);

        // update the topic of index to new_topic
        void set_topic(int index, int new_topic);

        inline size_t size() const {
            return _sentences.size();
        }

        inline Sentence &sent(size_t index) {
            return _sentences[index];
        }

    private:
        // the document is a set of sentence, each sentence has a topic
        std::vector<Sentence> _sentences;
    };
}


#endif //CPP_TUTORIAL_SENTENCE_DOCUMENT_H
