//
// Created by root on 2025/9/22.
//

#ifndef GTEST_PROJECT_TWOSUM_H
#define GTEST_PROJECT_TWOSUM_H

#include <vector>
#include <cstdint>

using namespace std;

namespace TwoSum
{
    class Solution
    {
    public:
        static vector<int32_t> TwoSum(const vector<int32_t> &nums, const int32_t target);
        static vector<int32_t> TwoSumWithHash(const vector<int32_t> &nums, const int32_t target);
    };
} // namespace TwoSum

#endif //GTEST_PROJECT_TWOSUM_H