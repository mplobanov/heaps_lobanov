//
// Created by Михаил Лобанов on 15.12.2019.
//

#ifndef HEAPS_SKEWHEAP_H
#define HEAPS_SKEWHEAP_H

//
// Created by Михаил Лобанов on 13.12.2019.
//

#ifndef HEAPS_SkewHeap_H
#define HEAPS_SkewHeap_H

#include "../meta_heap/MetaHeap.h"

class SkewHeap : public MetaHeap {
public:
    void meld(MetaHeap & oth) final;

    explicit SkewHeap(int key) : MetaHeap(key) {}

    SkewHeap() : MetaHeap() {}

    void insert(int key) override {
        auto new_heap = new SkewHeap(key);
            meld(*new_heap);
    }
};




#endif //HEAPS_SkewHeap_H
#endif //HEAPS_SKEWHEAP_H
