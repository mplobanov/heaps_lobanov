//
// Created by Михаил Лобанов on 12.12.2019.
//

#ifndef HEAPS_BINOMINALHEAP_H
#define HEAPS_BINOMINALHEAP_H

#include "../IHeap.h"
#include "binomial_tree/BinomialTree.h"

#include <vector>
#include <iostream>
#include <list>


class BinomialHeap : public IHeap {
    using root_list = std::list<BinomialTree *>;
private:
    root_list _roots = root_list();

    void meld_tree(BinomialTree &tree);

    explicit BinomialHeap(BinomialTree &tree);

public:
    void log();

    BinomialHeap(const BinomialHeap &other);

    ~BinomialHeap() = default;

    BinomialHeap &operator=(const BinomialHeap &other);

    BinomialHeap() = default;

    int get_min() override;


    void insert(int key) override;

    void meld(BinomialHeap &other);

    int extract_min() override;;

};


#endif //HEAPS_BINOMINALHEAP_H
