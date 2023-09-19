#include <climits>

#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
  public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dist(n * 2, INT_MAX);
        vector<int> selected(n * 2, 0);
        vector<vector<int>> edges(n * 2);
        for (auto& path : redEdges) {
            edges[path[0]].push_back(n + path[1]);
        }
        for (auto& path : blueEdges) {
            edges[path[0] + n].push_back(path[1]);
        }

        selected[0] = 1;
        dist[0] = 0;
        for (auto& v : edges[0]) {
            dist[v] = 1;
        }
        selected[n] = 1;
        dist[n] = 0;
        for (auto& v : edges[n]) {
            dist[v] = 1;
        }

        while (true) {
            int min = INT_MAX;
            int minIndex = -1;
            for (int i = 0; i < n * 2; i++) {
                if (selected[i] == 0 && dist[i] < min) {
                    min = dist[i];
                    minIndex = i;
                }
            }
            if (minIndex == -1) {
                break;
            }
            selected[minIndex] = 1;
            for (auto& v : edges[minIndex]) {
                if (dist[minIndex] + 1 < dist[v]) {
                    dist[v] = dist[minIndex] + 1;
                }
            }
        }

        vector<int> result(n, -1);

        for (int i = 0; i < n; i++) {
            result[i] = min(dist[i], dist[i + n]);
            if (result[i] == INT_MAX) {
                result[i] = -1;
            }
        }

        return result;
    }
};
// @lc code=end
