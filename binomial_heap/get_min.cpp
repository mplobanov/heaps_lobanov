//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

int BinomialHeap::get_min() {
    if (_roots.size() == 0)
        return 0;
    auto it = _roots.begin();
    int ans = (*it)->_key;
    ++it;
    while (it != _roots.end()) {
        ans = std::min(ans, (*it)->_key);
        it++;
    }
    return ans;
}







