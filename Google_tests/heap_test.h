//
// Created by Михаил Лобанов on 12.12.2019.
//

#ifndef HEAPS_HEAP_TEST_H
#define HEAPS_HEAP_TEST_H

#include "../SimpleHeap.h"
#include "lib/googletest/include/gtest/gtest.h"

#include <vector>

enum OperationType {AddHeap, Insert, GetMin, ExtractMin, Meld, None};

class Operation {
public:
    virtual OperationType get_operation_type() {
        return OperationType::None ;
    }

    virtual std::string toString() {
        return "Unknown operation";
    }
};

OperationType random_operation_type(){
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

namespace opers {

    class AddHeap : public Operation {
    private:
        OperationType  operationType = OperationType::AddHeap;
        int _key = 0;
    public:
        explicit AddHeap (int key) : _key(key) {}
        int key() {
            return _key;
        }

        std::string toString() override {
            return "Add Heap with inital key " + std::to_string(_key);
        }

        OperationType get_operation_type() override {
            return operationType;
        }
    };

    class Insert : public Operation {
    private:
        OperationType  operationType = OperationType::Insert;
        int _index = 0;
        int _key = 0;
    public:
        Insert (int index, int key) : _index(index), _key(key) {}
        int index() {
            return _index;
        }
        int key() {
            return _key;
        }

        std::string toString() override {
            std::string ans = "Insert " + std::to_string(_key);
            ans += " in Heap " + std::to_string(_index);
            return ans;
        }

        OperationType get_operation_type() override {
            return operationType;
        }
    };

    class GetMin : public Operation {
    private:
        OperationType  operationType = OperationType::GetMin;
        int _index = 0;
    public:
        explicit GetMin (int index) : _index(index) {}
        int index() {
            return _index;
        }

        std::string toString() override {
            return "Get min of Heap " + std::to_string(_index);
        }

        OperationType get_operation_type() override {
            return operationType;
        }
    };

    class ExtractMin : public Operation {
    private:
        OperationType  operationType = OperationType::ExtractMin;
        int _index = 0;
    public:
        explicit ExtractMin (int index) : _index(index) {}
        int index() {
            return _index;
        }

        std::string toString() override {
            return "Extract Min of Heap " + std::to_string(_index);
        }

        OperationType get_operation_type() override {
            return operationType;
        }
    };

    class Meld : public Operation {
    private:
        OperationType  operationType = OperationType::Meld;
        int _index1 = 0;
        int _index2 = 0;
    public:
        Meld(int index1, int index2) : _index1(index1), _index2(index2) {
            assert(index1 != index2);
        }
        int index1() {
            return _index1;
        }
        int index2() {
            return _index2;
        }

        std::string toString() override {
            std::string ans = "Meld Heaps " + std::to_string(_index1);
            ans += " and " + std::to_string(_index2);
            return ans;
        }

        OperationType get_operation_type() override {
            return operationType;
        }
    };
}


class HeapTest {
public:
    std::vector<Operation*> _operations;
    int _INT_MAX = 100;
public:
    int operations_count(){
        return _operations.size();
    }

    explicit HeapTest(int operations_count = 1000, int int_max = 100) : _INT_MAX(int_max) {
        _operations = std::vector<Operation*>();
        std::vector<int> heap_sizes;
        int i = 1;
        int key, index;
        key = rand() % _INT_MAX;
        _operations.push_back(new opers::AddHeap(key));
        heap_sizes.push_back(1);
        while (i < operations_count) {
            OperationType operationType = random_operation_type();
            i++;
            switch (operationType) {
                case OperationType::AddHeap:
                    key = rand() % _INT_MAX;
                    _operations.push_back(new opers::AddHeap(key));
                    heap_sizes.push_back(1);
                    break;
                case OperationType::Insert:
                    index = rand() % heap_sizes.size();
                    key = rand() % _INT_MAX;
                    heap_sizes[index]++;
                    _operations.push_back(new opers::Insert(index, key));
                    break;
                case OperationType::GetMin:
                    index = rand() % heap_sizes.size();
                    if (heap_sizes[index] == 0)
                        i--;
                    else
                        _operations.push_back(new opers::GetMin(index));
                    break;
                case OperationType::ExtractMin:
                    index = rand() % heap_sizes.size();
                    if (heap_sizes[index] == 0)
                        i--;
                    else {
                        _operations.push_back(new opers::ExtractMin(index));
                        heap_sizes[index]--;
                    }
                    break;
                case OperationType::None:
                    break;
                case OperationType::Meld:
                    int index1 = rand() % heap_sizes.size();
                    int index2 = rand() % heap_sizes.size();
                    if (index1 == index2)
                        i--;
                    else {
                        if (index1 > index2)
                            std::swap(index1, index2);
                        _operations.push_back(new opers::Meld(index1, index2));
                        heap_sizes[index1] += heap_sizes[index2];
                        heap_sizes.erase(heap_sizes.begin() + index2);
                    }
                    break;
            }
        }
    }

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

#endif //HEAPS_HEAP_TEST_H
