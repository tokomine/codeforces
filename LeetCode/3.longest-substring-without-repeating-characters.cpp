#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int ans = 0;
        if (s.size() < 1) {
            return 0;
        }
        int l = 0;
        int r = 0;
        st.insert(s[0]);
        ans = 1;

        while (l < s.size()) {
            if (r + 1 < s.size() && st.find(s[r + 1]) == st.end()) {
                r++;
                st.insert(s[r]);
                ans = max(ans, r - l + 1);
            } else {
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end
