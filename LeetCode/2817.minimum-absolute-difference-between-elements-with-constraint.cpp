#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2817 lang=cpp
 *
 * [2817] Minimum Absolute Difference Between Elements With Constraint
 */

// @lc code=start
class Solution {
  public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        st.insert(nums[0]);
        int ans = INT_MAX;
        for (int i = x; i < nums.size(); i++) {
            auto lower = st.lower_bound(nums[i]);
            if (lower != st.end()) {
                ans = min(ans, abs(nums[i] - *lower));
            }
            lower--;
            if (lower != st.end()) {
                ans = min(ans, abs(nums[i] - *lower));
            }
            if (i - x + 1 >= 0 && i - x + 1 < nums.size()) {
                st.insert(nums[i - x + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end
