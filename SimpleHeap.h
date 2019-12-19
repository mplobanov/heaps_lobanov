//
// Created by Михаил Лобанов on 12.12.2019.
//

#ifndef HEAPS_SIMPLEHEAP_H
#define HEAPS_SIMPLEHEAP_H

#include "IHeap.h"

#include <set>

class SimpleHeap : public IHeap {
private:
    std::multiset<int> _heap;
public:
    int size() {
        return _heap.size();
    }

    void insert(int key) override  {
        _heap.insert(key);
    }

    int extract_min() override {
        int min_key = *_heap.begin();
        _heap.erase(_heap.begin());
        return min_key;
    }

    int get_min() override {
        return *_heap.begin();
    }

    void meld (SimpleHeap & other) {
        _heap.merge(other._heap);
    }

    ~SimpleHeap() = default;
};

#endif //HEAPS_SIMPLEHEAP_H
