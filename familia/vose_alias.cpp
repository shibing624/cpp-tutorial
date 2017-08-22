//
// Created by Xu,Ming(RCPT) on 17/8/22.
//

#include "vose_alias.h"
#include "util.h"
#include <queue>

namespace familia {
    void VoseAlias::init(const std::vector<double> &dist) {
        int size = dist.size();
        _prob.resize(size);
        _alias.resize(size);
        std::vector<double> p(size, 0.0);
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += dist[i];
        }
        for (int i = 0; i < size; ++i) {
            p[i] = dist[i] / sum * size; // scale up probability
        }

        std::queue<double> large;
        std::queue<double> small;
        for (int i = 0; i < size; ++i) {
            if (p[i] < 1.0) {
                small.push((double) i);
            } else {
                large.push((double) i);
            }
        }
        while (!small.empty() && !large.empty()) {
            int l = small.front();
            int g = large.front();
            small.pop();
            large.pop();
            _prob[l] = p[l];
            _alias[l] = g;
            // a more numerically stable option
            p[g] = p[g] + p[l] - 1;
            if (p[g] < 1.0) {
                small.push(g);
            } else {
                large.push(g);
            }
        }
        while (!large.empty()) {
            int g = large.front();
            large.pop();
            _prob[g] = 1.0;
        }
        while (!small.empty()) {
            int l = small.front();
            small.pop();
            _prob[l] = 1.0;
        }
    }

    int VoseAlias::generate() const {
        int dart2 = rand();
        srand(size());
        int dart1 = rand();
        return dart2 > _prob[dart1] ? dart1 : _alias[dart1];
    }
} // namespace familia