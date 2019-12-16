//
// Created by Михаил Лобанов on 13.12.2019.
//

#ifndef HEAPS_LEFTISTHEAP_H
#define HEAPS_LEFTISTHEAP_H

#include "IHeap.h"

class LeftistHeap : public IHeap {
private:
    bool _is_empty = true;
    int _key = 0;
    LeftistHeap* _left = nullptr;
    LeftistHeap* _right = nullptr;
    int _rank = 0;

    void _rank_refresh(){
        if (_left == nullptr || _right == nullptr) {
            _rank = 1;
            return;
        }
        _rank = std::min(_left->_rank, _right->_rank) + 1;
    }

    void _swap(LeftistHeap & other) {
        std::swap(_is_empty, other._is_empty);
        std::swap(_key, other._key);
        std::swap(_left, other._left);
        std::swap(_right, other._right);
        std::swap(_rank, other._rank);
    }

    void _copy(LeftistHeap & other) {
        _is_empty = other._is_empty;
        _key = other._key;
        _left = other._left;
        _right = other._right;
        _rank = other._rank;
    }
public:
    explicit LeftistHeap(int key) : _key(key), _is_empty(false) {}
    LeftistHeap() = default;

    void meld(LeftistHeap & other) {
        if (other._is_empty)
            return;
        if (_is_empty) {
            _copy(other);
            return;
        }
        if (_key > other._key)
            _swap(other);

        if (_right == nullptr)
            _right = &other;
        else
            _right->meld(other);
        _rank_refresh();
        if (_left == nullptr){
            std::swap(_left, _right);
            return;
        }
        if ((_left->_rank) < (_right->_rank))
            std::swap(_left, _right);
        assert(_left->_rank >= _right->_rank);
    }

    int get_min() override {
        return _key;
    }

    void insert(int key) override {
        auto new_heap = new LeftistHeap(key);
        meld(*new_heap);
    }

    int extract_min() override {
        int min_key = _key;
        if (_left == nullptr && _right == nullptr){
            _key = 0;
            _is_empty = true;
        }
        else if (_left == nullptr) {
            _copy(*_right);
        }
        else if (_right == nullptr) {
            _copy(*_left);
        }
        else {
            _left->meld(*_right);
            _copy(*_left);
        }
        return min_key;
    }


};

#endif //HEAPS_LEFTISTHEAP_H
