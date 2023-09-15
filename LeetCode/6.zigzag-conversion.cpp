#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
  public:
    string convert(string s, int numRows) {
        vector<string> v;
        for (int i = 0; i < numRows; i++) {
            v.push_back("");
        }
        int row = 0;
        int direction = -1;
        for (int i = 0; i < s.size(); i++) {
            v[row] += s[i];
            if (numRows > 1) {
                if (row == 0 || row == numRows - 1) {
                    direction = -direction;
                }
                row += direction;
            }
        }
        string ans;
        for (auto &str : v) {
            ans += str;
        }
        return ans;
    }
};
// @lc code=end
