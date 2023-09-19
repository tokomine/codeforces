#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2798 lang=cpp
 *
 * [2798] Number of Employees Who Met the Target
 */

// @lc code=start
class Solution {
  public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n = 0;
        for (int x : hours) {
            if (x >= target) {
                n++;
            }
        }
        return n;
    }
};
// @lc code=end
