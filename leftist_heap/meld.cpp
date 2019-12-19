//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "LeftistHeap.h"

void LeftistHeap::meld(MetaHeap &oth) {
    MetaHeap::meld(oth);
    _rank_refresh();
    if (_left == nullptr){
        std::swap(_left, _right);
        return;
    }
    if(_right != nullptr){
        if ((dynamic_cast<LeftistHeap*>(_left)->_rank) < (dynamic_cast<LeftistHeap*>(_right)->_rank))
            std::swap(_left, _right);
    }
}
