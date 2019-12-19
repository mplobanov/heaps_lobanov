//
// Created by Михаил Лобанов on 16.12.2019.
//

#ifndef HEAPS_LEFTISTHEAP_H
#define HEAPS_LEFTISTHEAP_H

#include "../meta_heap/MetaHeap.h"

class LeftistHeap : public MetaHeap {
private:
    int _rank = 1;

    void _rank_refresh();

    void _swap(MetaHeap & other) final {
        MetaHeap::_swap(other);
        _rank = dynamic_cast<LeftistHeap*>(&other)->_rank;
    }
public:
    void meld(MetaHeap & oth) final;

    explicit LeftistHeap(int key);

    LeftistHeap();

    LeftistHeap(const LeftistHeap & other);

    void insert(int key) override {
        auto new_heap = new LeftistHeap(key);
        meld(*new_heap);
    }

    ~LeftistHeap() override {
        delete _left;
        delete _right;
    }
};



#endif //HEAPS_LEFTISTHEAP_H
