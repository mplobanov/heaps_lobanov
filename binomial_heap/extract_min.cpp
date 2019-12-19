//
// Created by Михаил Лобанов on 18.12.2019.
//
#include "BinominalHeap.h"

int BinomialHeap::extract_min() {
    int min_key = get_min();
    auto it = _roots.begin();
    if (it == _roots.end())
        return 0;
    while ((*it)->_key != min_key)
        ++it;
    _roots.erase(it);
    auto child = (*it)->_left_child;
    while (child != nullptr) {
        auto next_child = child->_right_sibling;
        meld_tree(*child);
        child = next_child;
    }
    return min_key;
}


