//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

void BinomialHeap::meld_tree(BinomialTree &tree) {
    auto it = _roots.begin();
    while (it != _roots.end() && (*it)->_degree < tree._degree)
        it++;
    _roots.insert(it, &tree);
    auto prev_it = it;
    --prev_it;
    while (it != _roots.end() && (*prev_it)->_degree == (*it)->_degree) {
        (*it)->unite(**prev_it);
        _roots.erase(prev_it);
        prev_it = it;
        ++it;
    }
}
