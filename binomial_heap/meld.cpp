//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

void BinomialHeap::meld(BinomialHeap &other) {
    auto it = other._roots.begin();
    while (it != other._roots.end()) {
        this->meld_tree(**it);
        ++it;
    }
}

