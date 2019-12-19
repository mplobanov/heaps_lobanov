//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "SkewHeap.h"

void SkewHeap::meld(MetaHeap &oth) {
    MetaHeap::meld(oth);
    std::swap(_left, _right);
}
