#define INPUT "../../../../LeetCode/test_case.txt"

#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            int res = target - v[i].first;
            int l = i + 1;
            int r = v.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (v[mid].first == res) {
                    return {v[i].second, v[mid].second};
                }
                else if (v[mid].first < res) {
                    l = mid + 1;
                }
                else if (v[mid].first > res) {
                    r = mid - 1;
                }
            }
        }
        return {};
    }
};
// @lc code=end

