#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2848 lang=cpp
 *
 * [2848] Points That Intersect With Cars
 */

// @lc code=start
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> v;
        for (int i = 0; i <= 100; i++) {
            v.push_back(0);
        }
        for (auto &n : nums) {
            int x = n[0];
            int y = n[1];
            for (int i=x;i<=y;i++) {
                v[i]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            if (v[i] != 0) {
                ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

