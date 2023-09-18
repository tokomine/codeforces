#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2840 lang=cpp
 *
 * [2840] Check if Strings Can be Made Equal With Operations II
 */

// @lc code=start
class Solution {
    string sub(const string& s, int bias) {
        string res;
        for (int i = 0 + bias; i < s.size(); i += 2) {
            res.push_back(s[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }

  public:
    bool checkStrings(string s1, string s2) { return sub(s1, 0) == sub(s2, 0) && sub(s1, 1) == sub(s2, 1); }
};
// @lc code=end
