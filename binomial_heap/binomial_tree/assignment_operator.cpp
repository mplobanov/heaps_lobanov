//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinomialTree.h"

BinomialTree &BinomialTree::operator=(const BinomialTree &other) {
    if (&other == this) return *this;
    _key = other._key;
    _degree = other._degree;
    _left_child = new BinomialTree(*other._left_child);
    _right_sibling = new BinomialTree(*other._right_sibling);
    return *this;
}
