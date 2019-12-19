//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "MetaHeap.h"

MetaHeap::MetaHeap(const MetaHeap &other) {
    _is_empty = other._is_empty;
    _key = other._key;
    _left = other._left;
    _right = other._right;
}

