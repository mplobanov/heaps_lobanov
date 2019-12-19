//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinomialTree.h"

BinomialTree::BinomialTree(const BinomialTree &other) {
    _key = other._key;
    _degree = other._degree;
    if (other._left_child != nullptr)
        _left_child = new BinomialTree(*other._left_child);
    if (other._right_sibling != nullptr)
        _right_sibling = new BinomialTree(*other._right_sibling);
}






