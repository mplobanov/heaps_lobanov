//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinomialTree.h"

void BinomialTree::unite(BinomialTree &other) {
    assert(_degree == other._degree);
    if (_key > other._key) {
        std::swap(_key, other._key);
        std::swap(_left_child, other._left_child);
        std::swap(_right_sibling, other._right_sibling);
    }
    other._right_sibling = _left_child;
    _left_child = &other;
    ++_degree;
}


