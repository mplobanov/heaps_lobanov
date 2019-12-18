//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "MetaHeap.h"

void MetaHeap::_swap(MetaHeap &other) {
    std::swap(_is_empty, other._is_empty);
    std::swap(_key, other._key);
    std::swap(_left, other._left);
    std::swap(_right, other._right);
}
