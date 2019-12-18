//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

void BinomialHeap::log() {
    int i = 1;
    auto it = _roots.begin();
    while (it != _roots.end()) {
        std::cout << "Tree " << i << std::endl;
        (*it)->log();
        ++it;
        ++i;
    }
    std::cout << std::endl;
}




