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

#include "IHeap.h"

class SkewHeap : public IHeap {
protected:
    bool _is_empty = true;
    int _key = 0;

    void _swap(SkewHeap & other) {
        std::swap(_is_empty, other._is_empty);
        std::swap(_key, other._key);
        std::swap(_left, other._left);
        std::swap(_right, other._right);
    }

    void _copy(SkewHeap & other) {
        _is_empty = other._is_empty;
        _key = other._key;
        _left = other._left;
        _right = other._right;
    }

protected:
    SkewHeap* _left = nullptr;
    SkewHeap* _right = nullptr;
public:
    explicit SkewHeap(int key) : _key(key), _is_empty(false) {}
    SkewHeap() = default;

    virtual void meld(SkewHeap & other) {
        if (other._is_empty)
            return;
        if (_is_empty) {
            _copy(other);
            return;
        }
        if (_key > other._key)
            _swap(other);
        if (_right == nullptr)
            _right = &other;
        else
            _right->meld(other);
        std::swap(_left, _right);
    }

    int get_min() override {
        return _key;
    }

    void insert(int key) override {
        auto new_heap = new SkewHeap(key);
        meld(*new_heap);
    }

    int extract_min() override {
        int min_key = _key;
        if (_left == nullptr && _right == nullptr){
            _key = 0;
            _is_empty = true;
        }
        else if (_left == nullptr) {
            _copy(*_right);
        }
        else if (_right == nullptr) {
            _copy(*_left);
        }
        else {
            _left->meld(*_right);
            _copy(*_left);
        }
        return min_key;
    }


};



#endif //HEAPS_SkewHeap_H
#endif //HEAPS_SKEWHEAP_H
