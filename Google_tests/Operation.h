//
// Created by Михаил Лобанов on 18.12.2019.
//

#ifndef HEAPS_OPERATION_H
#define HEAPS_OPERATION_H

#include <string>

enum OperationType {AddHeap, Insert, GetMin, ExtractMin, Meld, None};

class Operation {
public:
    virtual OperationType get_operation_type() const {
        return OperationType::None ;
    }

    virtual std::string toString() {
        return "Unknown operation";
    }
};



namespace opers {

    class AddHeap : public Operation {
    private:
        int _key = 0;
    public:
        explicit AddHeap (int key) : _key(key) {}
        int key() {
            return _key;
        }

        std::string toString() override {
            return "Add Heap with inital key " + std::to_string(_key);
        }

        OperationType get_operation_type() const override{
            return OperationType::AddHeap;
        }
    };

    class Insert : public Operation {
    private:
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

        OperationType get_operation_type() const override {
            return OperationType::Insert;
        }
    };

    class GetMin : public Operation {
    private:
        int _index = 0;
    public:
        explicit GetMin (int index) : _index(index) {}
        int index() {
            return _index;
        }

        std::string toString() override {
            return "Get min of Heap " + std::to_string(_index);
        }

        OperationType get_operation_type() const override {
            return OperationType::GetMin;
        }
    };

    class ExtractMin : public Operation {
    private:
        int _index = 0;
    public:
        explicit ExtractMin (int index) : _index(index) {}
        int index() {
            return _index;
        }

        std::string toString() override {
            return "Extract Min of Heap " + std::to_string(_index);
        }

        OperationType get_operation_type() const override {
            return OperationType::ExtractMin;
        }
    };

    class Meld : public Operation {
    private:
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

        OperationType get_operation_type() const override {
            return OperationType::Meld;
        }
    };
}

#endif //HEAPS_OPERATION_H
