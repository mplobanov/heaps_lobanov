//
// Created by Михаил Лобанов on 12.12.2019.
//
#include "gtest/gtest.h"
#include "../BinominalHeap.h"
#include "../SimpleHeap.h"
#include "../LeftistHeap.h"
#include "../SkewHeap.h"
#include "../LeftistHeap_Good.h"
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
void easy_stress_test(int iteration = 1000) {
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



class HeapTestStress : public ::testing::Test {
protected:
    virtual void SetUp() override {
        test = HeapTest(1'000'000, INT_MAX);
        answers = test.apply<SimpleHeap>();
    }

    HeapTest test;
    std::vector<int> answers;
};

void check_answers(const std::vector<int> & ans_check, const std::vector<int> & real_ans) {
    ASSERT_EQ(ans_check.size(), real_ans.size());
    for (int i = 0; i < ans_check.size(); ++i) {
        EXPECT_EQ(ans_check[i], real_ans[i]);
    }
}


TEST(HeapTestManual, simple_heap) {
    manual_test<SimpleHeap>();
}

TEST(HeapTestManual, binomial_heap) {
    manual_test<BinomialHeap>();
}

TEST(HeapTestManual, leftist_heap) {
    manual_test<LeftistHeap>();
}

TEST(HeapTestManual, skew_heap) {
    manual_test<SkewHeap>();
}

TEST(HeapTestEasy, binomial_heap) {
    easy_stress_test<BinomialHeap>(1'000'000);
}

TEST(HeapTestEasy, leftist_heap) {
    easy_stress_test<LeftistHeap>(1'000'000);
}

TEST(HeapTestEasy, skew_heap) {
    easy_stress_test<SkewHeap>(1'000'000);
}

TEST_F(HeapTestStress, binomial_heap) {
    std::vector<int> ans_check = test.apply<BinomialHeap>();
    check_answers(ans_check, answers);
}

TEST_F(HeapTestStress, leftist_heap) {
    std::vector<int> ans_check = test.apply<LeftistHeap>();
    check_answers(ans_check, answers);
}

TEST_F(HeapTestStress, simple_heap) {
    std::vector<int> ans_check = test.apply<SimpleHeap>();
    check_answers(ans_check, answers);
}

TEST_F(HeapTestStress, skew_heap) {
    std::vector<int> ans_check = test.apply<SkewHeap>();
    check_answers(ans_check, answers);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}