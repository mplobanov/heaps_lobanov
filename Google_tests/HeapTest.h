//
// Created by Михаил Лобанов on 12.12.2019.
//

#ifndef HEAPS_HEAPTEST_H
#define HEAPS_HEAPTEST_H

#include "Operation.h"

#include "lib/googletest/include/gtest/gtest.h"

#include <vector>

OperationType random_operation_type();

class HeapTest {
    friend class Insert;
public:
    std::vector<Operation*> _operations;
    std::vector<int> _heap_sizes;
    int _INT_MAX = 100;
    int operations_count(){
        return _operations.size();
    }

    explicit HeapTest() : _operations(std::vector<Operation*>()), _heap_sizes(std::vector<int>()) {}

    explicit HeapTest(int operations_count, int int_max = 100);

    void add_operation(Operation & operation) ;

    std::string toString() {
        std::string ans;
        ans.append("Test - ");
        ans.append(std::to_string(operations_count()));
        ans += " operations\n";
        for (Operation* operation : _operations) {
            ans += operation->toString() + "\n";
        }
        return ans;
    }


//
//    TEST APPLY
//

private:
    template <typename HeapType>
    void Add_Heap(int key, std::vector<HeapType*> & heaps) {
        HeapType* hp = new HeapType();
        hp->insert(key);
        heaps.push_back(hp);
    }

    template <typename HeapType>
    void Insert_in(int key, int index, std::vector<HeapType*> & heaps) {
        heaps[index]->insert(key);
    }

    template <typename HeapType>
    int Get_Min(int index, std::vector<HeapType*> & heaps) {
        return heaps[index]->get_min();
    }

    template <typename HeapType>
    int Extract_Min(int index, std::vector<HeapType*> & heaps) {
        return heaps[index]->extract_min();
    }

    template <typename HeapType>
    void Meld_Heaps(int index1, int index2, std::vector<HeapType*> & heaps) {
        heaps[index1]->meld(*heaps[index2]);
        heaps.erase(heaps.begin() + index2);
    }

public:
    template <typename HeapType>
    std::vector<int> apply() {
        std::vector<HeapType*> heaps;
        std::vector<int> ans;
        for (Operation* operation : _operations) {
            OperationType type = operation->get_operation_type();
            assert(type != OperationType::None);
            switch (type) {
                case OperationType::AddHeap:
                    Add_Heap(dynamic_cast<opers::AddHeap*>(operation)->key(), heaps);
                    break;
                case OperationType::Insert:
                    Insert_in(dynamic_cast<opers::Insert*>(operation)->key(), dynamic_cast<opers::Insert*>(operation)->index(), heaps);
                    break;
                case OperationType::GetMin:
                    ans.push_back(Get_Min(dynamic_cast<opers::GetMin*>(operation)->index(), heaps));
                    break;
                case OperationType::ExtractMin:
                    ans.push_back(Extract_Min(dynamic_cast<opers::ExtractMin*>(operation)->index(), heaps));
                    break;
                case OperationType::Meld:
                    Meld_Heaps(dynamic_cast<opers::Meld*>(operation)->index1(), dynamic_cast<opers::Meld*>(operation)->index2(), heaps);
                    break;
                case OperationType::None:
                    std::cout << "OMG" << std::endl;
            }
        }
        return ans;
    }

};

#endif //HEAPS_HEAPTEST_H
