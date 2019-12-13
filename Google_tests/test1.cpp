//
// Created by Михаил Лобанов on 12.12.2019.
//
#include "gtest/gtest.h"
#include "../BinominalHeap.h"
#include "../SimpleHeap.h"
#include "heap_test.h"

#include <vector>


template <typename HeapType>
void manual_test() {
    HeapType heap;
    heap.insert(5);
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    EXPECT_EQ(heap.get_min(), 1);
    EXPECT_EQ(heap.extract_min(), 1);
    EXPECT_EQ(heap.get_min(), 2);
    heap.insert(1);
    EXPECT_EQ(heap.get_min(), 1);
    heap.insert(1);
    EXPECT_EQ(heap.extract_min(), 1);
    EXPECT_EQ(heap.extract_min(), 1);
    EXPECT_EQ(heap.extract_min(), 2);
}

template <typename HeapType>
void stress_test(int iteration = 1000) {
    HeapType heap;
    SimpleHeap simple_heap;
    for (int i = 0; i < iteration; ++i) {
        int operation = rand() % 3;
        int key;
        switch (operation) {
            case 0:
                key = rand() % INT_MAX;
                heap.insert(key);
                simple_heap.insert(key);
            case 1:
                if (simple_heap.size() != 0){
                    EXPECT_EQ(simple_heap.get_min(), heap.get_min());
                }
            case 2:
                if (simple_heap.size() != 0){
                    EXPECT_EQ(simple_heap.extract_min(), heap.extract_min());
                }
            default:
                break;
        }
    }
}

template <typename HeapType>
void Add_Heap(int key, std::vector<HeapType*> & heaps) {
    HeapType* hp = new HeapType();
    hp->insert(key);
    heaps.push_back(hp);
}










TEST(BinomialHeapTests, manual_test_1) {
    manual_test<BinomialHeap>();
}

TEST(SimpleHeapTests, manual_test_1) {
    manual_test<SimpleHeap>();
}


TEST(BinomialHeapTests, stress_test) {
    stress_test<BinomialHeap>(1'000'000);
}

TEST(BinomialHeapTests, the_great_test_ever) {
    HeapTest tst = HeapTest(1'000'000, 2'000'000'000);
    std::vector<int> ans1 = tst.apply<BinomialHeap>();
    std::vector<int> ans2 = tst.apply<SimpleHeap>();
    ASSERT_EQ(ans1.size(), ans2.size());
    for (int i = 0; i < ans1.size(); ++i) {
        EXPECT_EQ(ans1[i], ans2[i]);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}