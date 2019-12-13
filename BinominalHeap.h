//
// Created by Михаил Лобанов on 12.12.2019.
//

#ifndef HEAPS_BINOMINALHEAP_H
#define HEAPS_BINOMINALHEAP_H

#include "IHeap.h"

#include <vector>
#include <iostream>
#include <list>


class BinomialHeap : public IHeap {
    class BinomialTree {
    public:
        int _key = 0;
        //BinomialTree* _parent = nullptr;
        BinomialTree *_left_child = nullptr;
        BinomialTree *_right_sibling = nullptr;
        int _degree = 0;

        explicit BinomialTree(int key) : _key(key) {}

        BinomialTree(const BinomialTree &other) {
            _key = other._key;
            _degree = other._degree;
            if (other._left_child != nullptr)
                _left_child = new BinomialTree(*other._left_child);
            if (other._right_sibling != nullptr)
                _right_sibling = new BinomialTree(*other._right_sibling);
        }

        BinomialTree &operator=(const BinomialTree &other) {
            if (&other == this) return *this;
            _key = other._key;
            _degree = other._degree;
            _left_child = new BinomialTree(*other._left_child);
            _right_sibling = new BinomialTree(*other._right_sibling);
            return *this;
        }

        ~BinomialTree() {
            if (_left_child != nullptr)
                _left_child->~BinomialTree();
            if (_right_sibling != nullptr)
                _right_sibling->~BinomialTree();
        }

        void unite(BinomialTree &other) {
            assert(_degree == other._degree);
            if (_key > other._key) {
                std::swap(_key, other._key);
                std::swap(_left_child, other._left_child);
                std::swap(_right_sibling, other._right_sibling);
            }
            other._right_sibling = _left_child;
            _left_child = &other;
            ++_degree;
        }

        void log(int tabs_count = 0) {
            if (_degree == 0) {
                for (int i = 0; i < tabs_count; ++i) std::cout << "\t";
                std::cout << "key: " << _key << std::endl;
                return;
            } else {
                for (int i = 0; i < tabs_count; ++i) std::cout << "\t";
                std::cout << "key: " << _key << std::endl;
                if (_left_child != nullptr)
                    _left_child->log(tabs_count + 1);
                if (_right_sibling != nullptr)
                    _right_sibling->log(tabs_count);
            }
        }

        std::list<BinomialTree *> get_siblings() {
            std::list<BinomialTree *> ans;
            ans.push_back(this);
            auto sibling = _right_sibling;
            while (_right_sibling != nullptr) {
                ans.push_back(sibling);
                sibling = sibling->_right_sibling;
            }
            return ans;
        }

        BinomialTree *get_left_child() {
            return _left_child;
        }

    };

    using root_list = std::list<BinomialTree *>;
private:
    root_list _roots = root_list();

    void meld_tree(BinomialTree &tree) {
        auto it = _roots.begin();
        while (it != _roots.end() && (*it)->_degree < tree._degree)
            it++;
        _roots.insert(it, &tree);
        auto prev_it = it;
        --prev_it;
        while (it != _roots.end() && (*prev_it)->_degree == (*it)->_degree) {
            (*it)->unite(**prev_it);
            _roots.erase(prev_it);
            prev_it = it;
            ++it;
        }
    }

    BinomialHeap(BinomialTree &tree) {
        _roots = root_list(1, new BinomialTree(tree));
    }

public:
    void log() {
        int i = 1;
        auto it = _roots.begin();
        while (it != _roots.end()) {
            std::cout << "Tree " << i << std::endl;
            (*it)->log();
            ++it;
            ++i;
        }
        std::cout << std::endl;
    }

    BinomialHeap(const BinomialHeap &other) {
        _roots = root_list();
        auto it = _roots.begin();
        while (it != _roots.end())
            _roots.push_back(new BinomialTree(**it));
    }

    ~BinomialHeap() = default;

    BinomialHeap &operator=(const BinomialHeap &other) {
        if (&other == this) return *this;
        _roots = root_list();
        auto it = _roots.begin();
        while (it != _roots.end())
            _roots.push_back(new BinomialTree(**it));
        return *this;
    }

    BinomialHeap() = default;

    int get_min() override {
        if (_roots.size() == 0)
            return 0;
        auto it = _roots.begin();
        int ans = (*it)->_key;
        ++it;
        while (it != _roots.end()) {
            ans = std::min(ans, (*it)->_key);
            it++;
        }
        return ans;
    }


    void insert(int key) override {
        BinomialTree *tree = new BinomialTree(key);
        this->meld_tree(*tree);
    }

    void meld(BinomialHeap &other) {
        auto it = other._roots.begin();
        while (it != other._roots.end()) {
            this->meld_tree(**it);
            ++it;
        }
    }

    int extract_min() override {
        int min_key = get_min();
        auto it = _roots.begin();
        while ((*it)->_key != min_key)
            ++it;
        _roots.erase(it);
        auto child = (*it)->_left_child;
        while (child != nullptr) {
            auto next_child = child->_right_sibling;
            meld_tree(*child);
            child = next_child;
        }
        return min_key;
    };

};

#endif //HEAPS_BINOMINALHEAP_H
