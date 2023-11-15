#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */

// @lc code=start
class Solution {
  public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        bool ok = true;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[j] || 'a' + (str1[i] - 'a' + 1) % 26 == str2[j]) {
                j++;
            }
        }
        return j == str2.size();
    }
};
// @lc code=end
