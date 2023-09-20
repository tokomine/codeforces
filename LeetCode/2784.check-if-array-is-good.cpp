#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2784 lang=cpp
 *
 * [2784] Check if Array is Good
 */

// @lc code=start
class Solution {
  public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != i + 1) return false;
        }
        if (nums[nums.size() - 1] != nums.size() - 1) return false;
        return true;
    }
};
// @lc code=end
