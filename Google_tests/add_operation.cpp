//
// Created by Михаил Лобанов on 18.12.2019.
//
#include "HeapTest.h"

void HeapTest::add_operation(Operation & operation) {
    auto operationType = operation.get_operation_type();

    // SWITCH does not allow to declare variables inside
    opers::GetMin* getmin_operation;
    opers::ExtractMin* extractmin_operation;
    opers::Meld* meld_operation;

    switch (operationType) {
        case OperationType::AddHeap:
            _heap_sizes.push_back(1);
            break;
        case OperationType::Insert:
            _heap_sizes[dynamic_cast<opers::Insert*>(&operation)->index()]++;
            break;
        case OperationType::GetMin:
            getmin_operation = dynamic_cast<opers::GetMin*>(&operation);
            assert(_heap_sizes[getmin_operation->index()] != 0);
            break;
        case OperationType::ExtractMin:
            extractmin_operation = dynamic_cast<opers::ExtractMin*>(&operation);
            assert(_heap_sizes[extractmin_operation->index()] != 0);
            _heap_sizes[extractmin_operation->index()]--;
            break;
        case OperationType::None:
            break;
        case OperationType::Meld:
            meld_operation = dynamic_cast<opers::Meld*>(&operation);
            assert(meld_operation->index1() < meld_operation->index2());
            _heap_sizes[meld_operation->index1()] += _heap_sizes[meld_operation->index2()];
            _heap_sizes.erase(_heap_sizes.begin() + meld_operation->index2());
            break;
    }
    _operations.push_back(&operation);
}


