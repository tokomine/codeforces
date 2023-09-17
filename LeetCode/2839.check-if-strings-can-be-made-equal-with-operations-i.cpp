#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2839 lang=cpp
 *
 * [2839] Check if Strings Can be Made Equal With Operations I
 */

// @lc code=start
class Solution {
  public:
    bool isSame(const string& s1, const string& s2, int i, int j) {
        if (s1[i] == s2[i] && s1[j] == s2[j]) {
            return true;
        }
        if (s1[i] == s2[j] && s1[j] == s2[i]) {
            return true;
        }
        return false;
    }
    bool canBeEqual(string s1, string s2) { return isSame(s1, s2, 0, 2) && isSame(s1, s2, 1, 3); }
};
// @lc code=end
