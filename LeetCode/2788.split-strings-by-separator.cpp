#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2788 lang=cpp
 *
 * [2788] Split Strings by Separator
 */

// @lc code=start
class Solution {
  public:
    vector<string> split(string& s, char sep) {
        vector<string> ans;
        int lastp = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == sep) {
                if (i > lastp + 1) {
                    string subs = s.substr(lastp + 1, i - lastp - 1);
                    ans.push_back(subs);
                }
                lastp = i;
            }
        }
        if (lastp != s.size() - 1) {
            string subs = s.substr(lastp + 1);
            ans.push_back(subs);
        }
        return ans;
    }
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (string& s : words) {
            auto parts = split(s, separator);
            for (string& t : parts) {
                if (t.empty()) {
                    continue;
                }
                ans.push_back(t);
            }
        }
        return ans;
    }
};
// @lc code=end
