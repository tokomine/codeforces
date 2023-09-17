#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2828 lang=cpp
 *
 * [2828] Check if a String Is an Acronym of Words
 */

// @lc code=start
class Solution {
  public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) {
            return false;
        }
        for (int i = 0; i < words.size(); i++) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
