//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "LeftistHeap.h"

void LeftistHeap::_rank_refresh() {
    if (_left == nullptr || _right == nullptr) {
        _rank = 1;
        return;
    }
    _rank = std::min(dynamic_cast<LeftistHeap*>(_left)->_rank, dynamic_cast<LeftistHeap*>(_right)->_rank) + 1;
}




