#include <setjmp.h>

#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2815 lang=cpp
 *
 * [2815] Max Pair Sum in an Array
 */

// @lc code=start
class Solution {
  public:
    int maxDigit(int x) {
        int maxD = 0;
        while (x > 0) {
            maxD = max(maxD, x % 10);
            x /= 10;
        }
        return maxD;
    }
    int maxSum(vector<int>& nums) {
        int maxNumber = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (maxDigit(nums[i]) == maxDigit(nums[j])) {
                    if (nums[i] + nums[j] > maxNumber) {
                        maxNumber = nums[i] + nums[j];
                    }
                }
            }
        }
        return maxNumber;
    }
};
// @lc code=end
