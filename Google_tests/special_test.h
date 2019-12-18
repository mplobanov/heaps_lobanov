//
// Created by Михаил Лобанов on 18.12.2019.
//

#ifndef HEAPS_SPECIAL_TEST_H
#define HEAPS_SPECIAL_TEST_H

#include "HeapTest.h"

namespace inner {
    // gint - get int
    int gint(int max_int){
        return rand() % max_int;
    }
}

using namespace inner;

// mint - max int
HeapTest insert_extract_test(int approx_test_size, int mint) {
    int i = 0;
    HeapTest & test = * new HeapTest();
    test.add_operation(* new opers::AddHeap(gint(mint)));
    for (int i = 0; i < (approx_test_size - 1) / 2; ++i) {
        test.add_operation(* new opers::Insert(0, gint(mint)));
        test.add_operation(* new opers::ExtractMin(0));
    }
    return test;
}

//mint - max int
HeapTest bigmeld_test(int approx_test_size, int mint) {
    HeapTest & test = * new HeapTest();
    test.add_operation(* new opers::AddHeap(rand() % mint));
    test.add_operation(* new opers::AddHeap(rand() % mint));
    for (int i = 0; i < approx_test_size; ++i) {
        test.add_operation(* new opers::AddHeap(gint(mint)));
        test.add_operation(* new opers::Meld(0, 2));
        test.add_operation(* new opers::GetMin(0));

        test.add_operation(* new opers::AddHeap(gint(mint)));
        test.add_operation(* new opers::Meld(1, 2));
        test.add_operation(* new opers::GetMin(1));
    }
    test.add_operation(* new opers::Meld(0, 1));
    for (int j = 0; j < approx_test_size * 2; ++j) {
        test.add_operation(* new opers::ExtractMin(0));
    }
    return test;
}

HeapTest smallmeld_test(int approx_test_size, int mint) {
    HeapTest & test = * new HeapTest();
    test.add_operation(* new opers::AddHeap(gint(mint)));
    for (int i = 0; i < approx_test_size; ++i) {
        test.add_operation(* new opers::AddHeap(gint(mint)));
    }
    for (int j = 0; j < approx_test_size; ++j) {
        test.add_operation(* new opers::Meld(0, 1));
        test.add_operation(* new opers::ExtractMin(0));
    }
    return test;
}

HeapTest bigheap_test(int approx_test_size, int mint) {
    HeapTest & test = * new HeapTest();
    test.add_operation(* new opers::AddHeap(gint(mint)));
    for (int i = 0; i < approx_test_size; ++i) {
        test.add_operation(* new opers::Insert(0, gint(mint)));
    }
    for (int i = 0; i < approx_test_size; ++i) {
        test.add_operation(* new opers::ExtractMin(0));
    }
    return test;
}

#endif //HEAPS_SPECIAL_TEST_H
