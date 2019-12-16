//
// Created by Михаил Лобанов on 16.12.2019.
//

#ifndef HEAPS_LEFTISTHEAP_GOOD_H
#define HEAPS_LEFTISTHEAP_GOOD_H

#include "SkewHeap.h"

class LeftistHeapGood : public SkewHeap {
private:
    int _rank = 0;
    LeftistHeapGood* _left = nullptr;
    LeftistHeapGood* _right = nullptr;

    void _rank_refresh(){
        if (_left == nullptr || _right == nullptr) {
            _rank = 1;
            return;
        }
        _rank = std::min(_left->_rank, _right->_rank) + 1;
    }

public:
    void meld(LeftistHeapGood & other) {
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
        _rank_refresh();
        if (_left == nullptr){
            std::swap(_left, _right);
            return;
        }
        if ((_left->_rank) < (_right->_rank))
            std::swap(_left, _right);
    }
};

#endif //HEAPS_LEFTISTHEAP_GOOD_H
