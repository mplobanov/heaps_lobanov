//
// Created by Михаил Лобанов on 18.12.2019.
//

#ifndef HEAPS_METAHEAP_H
#define HEAPS_METAHEAP_H

#include <typeinfo>
#include <iostream>
#include "../IHeap.h"


class MetaHeap : public IHeap {
protected:
    int _key = 0;
    MetaHeap* _left = nullptr;
    MetaHeap* _right = nullptr;

    virtual void _swap(MetaHeap & other);

    bool _is_empty = true;
public:
    explicit MetaHeap(int key) : _key(key), _is_empty(false) {}

    MetaHeap() = default;

    MetaHeap(const MetaHeap & other);

    virtual void meld(MetaHeap & other) {
        if (other._is_empty)
            return;
        if (_is_empty) {
            *this = other;
            return;
        }
        if (_key > other._key)
            _swap(other);

        if (_right == nullptr)
            _right = &other;
        else
            _right->meld(other);
    };

    int get_min() override {
        return _key;
    }

    virtual void insert(int key) override = 0;

    int extract_min() override;

    virtual ~MetaHeap() = default;


};




#endif //HEAPS_METAHEAP_H
