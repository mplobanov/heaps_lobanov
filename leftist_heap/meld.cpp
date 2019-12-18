//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "LeftistHeap.h"

void LeftistHeap::meld(MetaHeap &oth) {
    auto other = dynamic_cast<LeftistHeap*>(&oth);
    if (other->_is_empty)
        return;
    if (_is_empty) {
        *this = *other;
        return;
    }
    if (_key > other->_key)
        _swap(*other);

    if (_right == nullptr)
        _right = other;
    else
        _right->meld(*other);
    _rank_refresh();
    if (_left == nullptr){
        std::swap(_left, _right);
        return;
    }
    if ((dynamic_cast<LeftistHeap*>(_left)->_rank) < (dynamic_cast<LeftistHeap*>(_right)->_rank))
        std::swap(_left, _right);
}
