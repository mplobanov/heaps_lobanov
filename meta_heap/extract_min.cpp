//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "MetaHeap.h"

int MetaHeap::extract_min() {
    int min_key = _key;
    if (_left == nullptr && _right == nullptr){
        _key = 0;
        _is_empty = true;
    }
    else if (_left == nullptr) {
        *this = *_right;
    }
    else if (_right == nullptr) {
        *this = *_left;
    }
    else {
        _left->meld(*_right);
        *this = *_left;
    }
    return min_key;
}



