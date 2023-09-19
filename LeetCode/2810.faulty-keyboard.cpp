#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2810 lang=cpp
 *
 * [2810] Faulty Keyboard
 */

// @lc code=start
class Solution {
  public:
    void reverse(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
    string finalString(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'i') {
                reverse(ans);
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
// @lc code=end
