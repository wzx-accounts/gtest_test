//
// Created by root on 2025/10/11.
//

#include "climb_stairs.h"
#include "gtest/gtest.h"

class ClimbStairsTest: public ::testing::Test
{

};

TEST_F(ClimbStairsTest, SolutionTest)
{
    EXPECT_EQ(ClimbStairs::Solution::climbStairs(1), 1);
    EXPECT_EQ(ClimbStairs::Solution::climbStairs(2), 2);
    EXPECT_EQ(ClimbStairs::Solution::climbStairs(3), 3);
    EXPECT_EQ(ClimbStairs::Solution::climbStairs(4), 5);
    EXPECT_EQ(ClimbStairs::Solution::climbStairs(5), 8);
}