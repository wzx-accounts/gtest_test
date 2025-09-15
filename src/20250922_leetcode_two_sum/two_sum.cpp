//
// Created by root on 2025/9/22.
//

#include "two_sum.h"
#include <unordered_map>

vector<int32_t> TwoSum::Solution::TwoSum(const vector<int32_t> &nums, const int32_t target)
{
    for (int32_t i = 0; i < nums.size(); i += 1) {
        for (int32_t j = i + 1; j < nums.size(); j += 1) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {};
}

vector<int32_t> TwoSum::Solution::TwoSumWithHash(const vector<int32_t> &nums, const int32_t target)
{
    std::unordered_map<int32_t, int32_t> hashTable;
    // for循环O(N)的复杂度
    for (int32_t i = 0; i < nums.size(); i += 1) {
        int32_t expected = target - nums[i];
        // map取值O(1)的复杂度
        if (hashTable.find(expected) != hashTable.end()) {
            return {hashTable[expected], i};
        }
        // map插入O(1)
        hashTable.insert({nums[i], i});
    }
    return {};
}
