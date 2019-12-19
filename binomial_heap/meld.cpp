//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinominalHeap.h"

//void BinomialHeap::meld(BinomialHeap &other) {
//    auto it = other._roots.begin();
//    while (it != other._roots.end()) {
//        this->meld_tree(**it);
//        ++it;
//    }
//}

void BinomialHeap::meld(BinomialHeap &other) {
    auto it_other = other._roots.begin();

    auto it_mine = _roots.begin();
    while (it_other != other._roots.end() && it_mine != _roots.end())
    {
        if ((*it_other)->_degree == (*it_mine)->_degree){
            (*it_mine)->unite(**it_other);
            it_other++;
            continue;
        }
        else if ((*it_other)->_degree < (*it_mine)->_degree){
            _roots.insert(it_mine, *it_other);
            it_other++;
        }
        else if ((*it_other)->_degree > (*it_mine)->_degree)
            it_mine++;
    }
    while (it_other != other._roots.end()){
        _roots.push_back(*it_other);
        it_other++;
    }
}

