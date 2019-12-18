//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinomialTree.h"

BinomialTree::~BinomialTree() {
    if (_left_child != nullptr)
        _left_child->~BinomialTree();
    if (_right_sibling != nullptr)
        _right_sibling->~BinomialTree();
}
