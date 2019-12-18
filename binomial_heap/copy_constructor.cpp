//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

BinomialHeap::BinomialHeap(const BinomialHeap &other) {
    _roots = root_list();
    auto it = _roots.begin();
    while (it != _roots.end())
        _roots.push_back(new BinomialTree(**it));
}
