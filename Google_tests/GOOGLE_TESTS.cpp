//
// Created by Михаил Лобанов on 12.12.2019.
//
#include "HeapTest.h" // Test utility
#include "gtest/gtest.h"
#include "../binomial_heap/BinominalHeap.h"
#include "../SimpleHeap.h"
#include "../skew_heap/SkewHeap.h"
#include "../leftist_heap/LeftistHeap.h"
#include "special_test.h" // Special Tests


int TEST_SIZE = 10'000; // not the exact amount of operations, but approximate
int MAXIMUM_INT = 20; // long and strange name in order not to confuse with INT_MAX constants


class HeapTest_RandomStress : public ::testing::Test {
protected:
    virtual void SetUp() override {
        test = HeapTest(TEST_SIZE, MAXIMUM_INT);
        answers = test.apply<SimpleHeap>();
    }

    HeapTest test;
    std::vector<int> answers;
};

class InsertExtractTest : public ::testing::Test {
protected:
    virtual void SetUp() override {
        test = insert_extract_test(TEST_SIZE, MAXIMUM_INT);
        answers = test.apply<SimpleHeap>();
    }

    HeapTest test;
    std::vector<int> answers;
};

class BigMeldTest : public ::testing::Test {
protected:
    virtual void SetUp() override {
        test = bigmeld_test(TEST_SIZE, MAXIMUM_INT);
        answers = test.apply<SimpleHeap>();
    }

    HeapTest test;
    std::vector<int> answers;
};

class SmallMeldTest : public ::testing::Test {
protected:
    virtual void SetUp() override {
        test = smallmeld_test(TEST_SIZE, MAXIMUM_INT);
        answers = test.apply<SimpleHeap>();
    }

    HeapTest test;
    std::vector<int> answers;
};

class BigHeapTest : public ::testing::Test {
protected:
    virtual void SetUp() override {
        test = bigheap_test(TEST_SIZE, MAXIMUM_INT);
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

TEST_F(HeapTest_RandomStress, binomial_heap) {
    std::vector<int> ans_check = test.apply<BinomialHeap>();
    check_answers(ans_check, answers);
}

TEST_F(HeapTest_RandomStress, leftist_heap) {
    std::vector<int> ans_check = test.apply<LeftistHeap>();
    check_answers(ans_check, answers);
}

TEST_F(HeapTest_RandomStress, simple_heap) {
    std::vector<int> ans_check = test.apply<SimpleHeap>();
    check_answers(ans_check, answers);
}

TEST_F(HeapTest_RandomStress, skew_heap) {
    std::vector<int> ans_check = test.apply<SkewHeap>();
    check_answers(ans_check, answers);
}

TEST_F(InsertExtractTest, binomial_heap) {
    std::vector<int> ans_check = test.apply<BinomialHeap>();
    check_answers(ans_check, answers);
}

TEST_F(InsertExtractTest, leftist_heap) {
    std::vector<int> ans_check = test.apply<LeftistHeap>();
    check_answers(ans_check, answers);
}

TEST_F(InsertExtractTest, simple_heap) {
    std::vector<int> ans_check = test.apply<SimpleHeap>();
    check_answers(ans_check, answers);
}

TEST_F(InsertExtractTest, skew_heap) {
    std::vector<int> ans_check = test.apply<SkewHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigMeldTest, binomial_heap) {
    std::vector<int> ans_check = test.apply<BinomialHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigMeldTest, leftist_heap) {
    std::vector<int> ans_check = test.apply<LeftistHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigMeldTest, simple_heap) {
    std::vector<int> ans_check = test.apply<SimpleHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigMeldTest, skew_heap) {
    std::vector<int> ans_check = test.apply<SkewHeap>();
    check_answers(ans_check, answers);
}

TEST_F(SmallMeldTest, binomial_heap) {
    std::vector<int> ans_check = test.apply<BinomialHeap>();
    check_answers(ans_check, answers);
}

TEST_F(SmallMeldTest, leftist_heap) {
    std::vector<int> ans_check = test.apply<LeftistHeap>();
    check_answers(ans_check, answers);
}

TEST_F(SmallMeldTest, simple_heap) {
    std::vector<int> ans_check = test.apply<SimpleHeap>();
    check_answers(ans_check, answers);
}

TEST_F(SmallMeldTest, skew_heap) {
    std::vector<int> ans_check = test.apply<SkewHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigHeapTest, binomial_heap) {
    std::vector<int> ans_check = test.apply<BinomialHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigHeapTest, leftist_heap) {
    std::vector<int> ans_check = test.apply<LeftistHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigHeapTest, simple_heap) {
    std::vector<int> ans_check = test.apply<SimpleHeap>();
    check_answers(ans_check, answers);
}

TEST_F(BigHeapTest, skew_heap) {
    std::vector<int> ans_check = test.apply<SkewHeap>();
    check_answers(ans_check, answers);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}