//
// Created by root on 2025/10/11.
//

#include "climb_stairs.h"
#include "cstdint"

namespace ClimbStairs
{
    int Solution::climbStairs(int n)
    {
        // dp[i] = dp[i-2] + 2
        int32_t dp1 = 1;
        int32_t dp2 = 2;

        if (n == 1) {
            return dp1;
        } else if (n == 2) {
            return dp2;
        }

        int32_t result = dp1 + 2;
        int32_t i_1 = dp2;
        int32_t i_2 = dp1;
        for (int32_t i = 3; i <= n; ++i) {
            result = i_2 + i_1;
            i_2 = i_1;
            i_1 = result;
        }
        return result;
    }
} // namespace ClimbStairs