#include <vector>

#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2799 lang=cpp
 *
 * [2799] Count Complete Subarrays in an Array
 */

// @lc code=start
class Solution {
  public:
    int countCompleteSubarrays(vector<int>& nums) {
        int l = 0, r = 0;
        int ans = 0;
        set<int> st(nums.begin(), nums.end());
        map<int, int> m;
        while (r < nums.size()) {
            m[nums[r]]++;
            while (l <= r && m.size() == st.size()) {
                m[nums[l]]--;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
                ans += nums.size() - r;
            }
            r++;
        }
        return ans;
    }
};
// @lc code=end
