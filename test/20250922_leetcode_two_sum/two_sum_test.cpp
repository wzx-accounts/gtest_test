//
// Created by root on 2025/9/22.
//

#include "gtest/gtest.h"
#include "iostream"
#include "two_sum.h"
using namespace std;

class TwoSumTest : public ::testing::Test
{
protected:
    void SetUp() override { cout << "two_sum_test SetUp." << endl; }
    void TearDown() override { cout << "two_sum_test TearDown." << endl; }
    static void SetupTestCase() { cout << "two_sum_test SetupTestCase." << endl; }
    static void TearDownTest() { cout << "two_sum_test TearDownTest." << endl; }
};

TEST_F(TwoSumTest, NormalTest01)
{
    vector<int32_t> nums{2, 7, 11, 15};
    int32_t target = 9;
    vector<int32_t> expected{0, 1};

    vector<int32_t> result01 = TwoSum::Solution::TwoSum(nums, target);
    EXPECT_EQ(expected, result01);

    vector<int32_t> result02 = TwoSum::Solution::TwoSumWithHash(nums, target);
    EXPECT_EQ(expected, result02);
}

TEST_F(TwoSumTest, NormalTest02)
{
    vector<int32_t> nums{3, 2, 4};
    int32_t target = 6;
    vector<int32_t> expected{1, 2};

    vector<int32_t> result01 = TwoSum::Solution::TwoSum(nums, target);
    EXPECT_EQ(expected, result01);

    vector<int32_t> result02 = TwoSum::Solution::TwoSumWithHash(nums, target);
    EXPECT_EQ(expected, result02);
}

TEST_F(TwoSumTest, NormalTest03)
{
    vector<int32_t> nums{3, 3};
    int32_t target = 6;
    vector<int32_t> expected{0, 1};

    vector<int32_t> result01 = TwoSum::Solution::TwoSum(nums, target);
    EXPECT_EQ(expected, result01);

    vector<int32_t> result02 = TwoSum::Solution::TwoSumWithHash(nums, target);
    EXPECT_EQ(expected, result02);
}
