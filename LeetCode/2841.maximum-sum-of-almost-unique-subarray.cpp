#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2841 lang=cpp
 *
 * [2841] Maximum Sum of Almost Unique Subarray
 */

// @lc code=start
struct State {
  public:
    int m;
    int k;
    bool isOk = false;
    long long sum = 0;
    int distinctNum = 0;
    map<int, int> dict;
    State(int m, int k) : m(m), k(k) {}
    void init(int x) {
        dict[x]++;
        if (dict[x] == 1) {
            distinctNum++;
        }
        sum += x;
        if (distinctNum >= m) {
            isOk = true;
        } else {
            isOk = false;
        }
    }
    long long add(int x, int preX) {
        init(x);
        dict[preX]--;
        if (dict[preX] == 0) {
            distinctNum--;
        }
        sum -= preX;
        if (distinctNum >= m) {
            isOk = true;
        } else {
            isOk = false;
        }
        if (!isOk) {
            return 0;
        }
        return sum;
    }
};

class Solution {
  public:
    long long maxSum(vector<int>& nums, int m, int k) {
        State state(m, k);
        for (int i = 0; i < k; i++) {
            state.init(nums[i]);
        }
        long long ans = state.isOk ? state.sum : 0;
        for (int i = k; i < nums.size(); i++) {
            ans = max(ans, state.add(nums[i], nums[i - k]));
        }
        return ans;
    }
};
// @lc code=end
