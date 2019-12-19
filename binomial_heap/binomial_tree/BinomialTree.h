//
// Created by Михаил Лобанов on 19.12.2019.
//

#ifndef HEAPS_BINOMIALTREE_H
#define HEAPS_BINOMIALTREE_H

#include <list>
#include <iostream>

class BinomialTree {
public:
    int _key = 0;
    BinomialTree *_left_child = nullptr;
    BinomialTree *_right_sibling = nullptr;
    int _degree = 0;

    explicit BinomialTree(int key) : _key(key) {}

    BinomialTree(const BinomialTree &other);

    BinomialTree &operator=(const BinomialTree &other);

    ~BinomialTree();

    void unite(BinomialTree &other);

    void log(int tabs_count = 0);

};



#endif //HEAPS_BINOMIALTREE_H
