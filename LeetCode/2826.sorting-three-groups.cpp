#include <vector>

#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2826 lang=cpp
 *
 * [2826] Sorting Three Groups
 */

// @lc code=start
class Solution {
  public:
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(3, 0));
        for (int i = 1; i <= nums.size(); i++) {
            dp[i][0] = dp[i - 1][0] + (nums[i - 1] != 1);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (nums[i - 1] != 2);
            dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + (nums[i - 1] != 3);
        }
        return min(dp[nums.size()][0], min(dp[nums.size()][1], dp[nums.size()][2]));
    }
};
// @lc code=end
