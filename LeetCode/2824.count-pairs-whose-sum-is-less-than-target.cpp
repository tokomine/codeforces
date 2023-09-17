#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2824 lang=cpp
 *
 * [2824] Count Pairs Whose Sum is Less than Target
 */

// @lc code=start
class Solution {
  public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                if (sum < target) {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
