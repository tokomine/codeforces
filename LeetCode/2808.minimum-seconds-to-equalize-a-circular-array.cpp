#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2808 lang=cpp
 *
 * [2808] Minimum Seconds to Equalize a Circular Array
 */

// @lc code=start
class Solution {
  public:
    int minimumSeconds(vector<int>& nums) {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (const auto& pair : m) {
            int n = pair.first;
            const auto& v = pair.second;
            int maxDiff = -999;
            if (v.size() == 1) {
                maxDiff = nums.size() / 2;
            } else {
                for (int i = 0; i < v.size(); i++) {
                    int diff = (v[(i + 1) % v.size()] - v[i] + nums.size()) % nums.size();
                    diff = diff / 2;
                    maxDiff = max(maxDiff, diff);
                }
            }
            ans = min(ans, maxDiff);
        }
        return ans;
    }
};
// @lc code=end
