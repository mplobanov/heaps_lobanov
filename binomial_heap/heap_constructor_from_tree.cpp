//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

BinomialHeap::BinomialHeap(BinomialTree &tree) {
    _roots = root_list(1, new BinomialTree(tree));
}
