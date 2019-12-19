//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

void BinomialHeap::insert(int key) {
    BinomialTree *tree = new BinomialTree(key);
    this->meld_tree(*tree);
}
