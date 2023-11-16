#include <vector>

#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2811 lang=cpp
 *
 * [2811] Check if it is Possible to Split Array
 */

// @lc code=start
class Solution {
  public:
    bool canSplitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        vector<int> sum(nums.size() + 1, 0);
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            dp[i][i + 1] = 1;
        }
        for (int k = 2; k < nums.size(); k++) {
            for (int i = 0; i + k < nums.size(); i++) {
                int l = i, r = i + k;
                dp[l][r] = 0;
                for (int j = l; j <= r - 1; j++) {
                    if (dp[l][j] == 0) {
                        continue;
                    }
                    if (dp[j + 1][r] == 0) {
                        continue;
                    }
                    if (j - l != 0 && sum[j] - sum[l] + nums[l] < m) {
                        continue;
                    }
                    if (r - j - 1 != 0 && sum[r] - sum[j + 1] + nums[j + 1] < m) {
                        continue;
                    }
                    dp[l][r] = 1;
                    break;
                }
            }
        }

        return dp[0][nums.size() - 1];
    }
};
// @lc code=end
