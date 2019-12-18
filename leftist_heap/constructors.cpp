//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "LeftistHeap.h"

LeftistHeap::LeftistHeap(int key) : MetaHeap(key) {
    _rank = 0;
}

LeftistHeap::LeftistHeap() : MetaHeap() {
    _rank = 0;
}

LeftistHeap::LeftistHeap(const LeftistHeap &other) : MetaHeap(other) {
    _rank = other._rank;
}


