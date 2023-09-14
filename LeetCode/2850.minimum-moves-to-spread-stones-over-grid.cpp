#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2850 lang=cpp
 *
 * [2850] Minimum Moves to Spread Stones Over Grid
 */

// @lc code=start
class Solution {
  public:
    bool isOk(vector<vector<int>>& grid) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    vector<tuple<int, int, int, int>> findAllPath(vector<vector<int>>& grid) {
        vector<tuple<int, int, int, int>> path;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] <= 1) {
                    continue;
                }
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (grid[k][l] > 0) {
                            continue;
                        }
                        path.push_back({i, j, k, l});
                    }
                }
            }
        }
        return path;
    }

    int dfs(vector<vector<int>>& grid) {
        if (isOk(grid)) {
            return 0;
        }
        auto paths = findAllPath(grid);
        int bestCost = -1;
        for (auto [i, j, k, l] : paths) {
            grid[i][j]--;
            grid[k][l]++;
            int cnt = dfs(grid);
            if (bestCost == -1 || cnt + abs(i - k) + abs(j - l) < bestCost) {
                bestCost = cnt + abs(i - k) + abs(j - l);
            }
            grid[i][j]++;
            grid[k][l]--;
        }
        return bestCost;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        int cnt = 0;
        return dfs(grid);
    }
};
// @lc code=end

// [[0,2,3],[2,0,1],[0,1,0]]
// 6

// [[1,3,0],[1,0,0],[1,0,3]]
// 4

// [[1,1,0],[1,1,1],[1,2,1]]
// 3
