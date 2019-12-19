//
// Created by Михаил Лобанов on 18.12.2019.
//
#include "HeapTest.h"

HeapTest::HeapTest(int operations_count, int int_max) {
    _operations = std::vector<Operation*>();
    int i = 1;
    int key, index;
    key = rand() % _INT_MAX;
    add_operation(*new opers::AddHeap(key));
    while (i < operations_count) {
        OperationType operationType = random_operation_type();
        i++;
        switch (operationType) {
            case OperationType::AddHeap:
                key = rand() % _INT_MAX;
                add_operation(*new opers::AddHeap(key));
                break;
            case OperationType::Insert:
                index = rand() % _heap_sizes.size();
                key = rand() % _INT_MAX;
                add_operation(*new opers::Insert(index, key));
                break;
            case OperationType::GetMin:
                index = rand() % _heap_sizes.size();
                if (_heap_sizes[index] == 0)
                    i--;
                else
                    add_operation(*new opers::GetMin(index));
                break;
            case OperationType::ExtractMin:
                index = rand() % _heap_sizes.size();
                if (_heap_sizes[index] == 0)
                    i--;
                else {
                    add_operation(*new opers::ExtractMin(index));
                }
                break;
            case OperationType::None:
                break;
            case OperationType::Meld:
                int index1 = rand() % _heap_sizes.size();
                int index2 = rand() % _heap_sizes.size();
                if (index1 == index2)
                    i--;
                else {
                    if (index1 > index2)
                        std::swap(index1, index2);
                    add_operation(*new opers::Meld(index1, index2));
                }
                break;
        }
    }
}

