//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "SkewHeap.h"

void SkewHeap::meld(MetaHeap &oth) {
    auto other = dynamic_cast<SkewHeap*>(&oth);
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
    std::swap(_left, _right);
}
