//
// Created by Михаил Лобанов on 19.12.2019.
//
#include "BinomialTree.h"

void BinomialTree::log(int tabs_count) {
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
