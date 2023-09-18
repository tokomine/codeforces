#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution {
  public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> a(n + 1, vector<int>(n + 1, -1));
        vector<int> selected(n + 1, 0);
        vector<int> dist(n + 1, INT_MAX);
        for (const auto& t : times) {
            a[t[0]][t[1]] = t[2];
        }
        selected[k] = 1;
        dist[k] = 0;
        int ans = -1;
        for (int _ = 1; _ < n; _++) {
            for (int i = 1; i <= n; i++) {
                if (selected[i] == 1) {
                    for (int j = 1; j <= n; j++) {
                        if (selected[j] == 0 && a[i][j] != -1) {
                            dist[j] = min(dist[j], dist[i] + a[i][j]);
                        }
                    }
                }
            }
            int min = INT_MAX;
            int min_index = -1;
            for (int i = 1; i <= n; i++) {
                // cout << dist[i] << " ";
                if (selected[i] == 0 && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }
            // cout << endl;
            if (min_index == -1) {
                break;
            }
            selected[min_index] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            if (dist[i] > ans) {
                ans = dist[i];
            }
        }
        return ans;
    }
};
// @lc code=end
