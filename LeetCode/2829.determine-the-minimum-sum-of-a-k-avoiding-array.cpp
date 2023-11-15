#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2829 lang=cpp
 *
 * [2829] Determine the Minimum Sum of a k-avoiding Array
 */

// @lc code=start
class Solution {
  public:
    int minimumSum(int n, int k) {
        set<int> st;
        vector<int> ans;
        for (int i = 1; i <= 2 * n; i++) {
            if (st.find(i) != st.end()) {
                continue;
            }
            st.insert(k - i);
            ans.push_back(i);
            if (ans.size() == n) {
                break;
            }
        }
        int sum = 0;
        for (auto v : ans) {
            sum += v;
        }
        return sum;
    }
};
// @lc code=end
