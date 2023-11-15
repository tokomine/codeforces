#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2830 lang=cpp
 *
 * [2830] Maximize the Profit as the Salesman
 */

// @lc code=start

struct Seg {
    int l, r, v;
    Seg(int l, int r, int v) : l(l), r(r), v(v) {}
    bool operator<(const Seg& s) const { return r < s.r; }
};

class Solution {
  public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<Seg>> m(n + 1);
        for (const auto& vec : offers) {
            Seg seg = {vec[0] + 1, vec[1] + 1, vec[2]};
            m[seg.r].push_back(seg);
        }
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
            const auto& p = m[i];
            for (auto& seg : p) {
                int l = seg.l;
                int r = seg.r;
                int v = seg.v;
                dp[r] = max(dp[r], dp[l - 1] + v);
            }
        }
        return dp[n];
    }
};
// @lc code=end
