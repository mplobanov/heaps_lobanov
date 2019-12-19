//
// Created by Михаил Лобанов on 18.12.2019.
//
#include "HeapTest.h"

OperationType random_operation_type() {
    int mode = rand() % 5;
    switch (mode) {
        case 0:
            return OperationType::AddHeap;
        case 1:
            return OperationType::Insert;
        case 2:
            return OperationType::GetMin;
        case 3:
            return OperationType::ExtractMin;
        case 4:
            return OperationType::Meld;
    }
    return OperationType::Meld;
}

