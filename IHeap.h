//
// Created by Михаил Лобанов on 12.12.2019.
//

#ifndef HEAPS_IHEAP_H
#define HEAPS_IHEAP_H

class IHeap {
public:
    virtual void insert(int) = 0;
    virtual int get_min() = 0;
    virtual int extract_min() = 0;
};

#endif //HEAPS_IHEAP_H
