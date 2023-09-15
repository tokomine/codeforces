#include <vector>

#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> f;
    vector<vector<pair<int, int>>> path;
    int dp(const string& s, int i, int j) {
        if (i == j) {
            path[i][j] = {i, j};
            return 1;
        }
        if (i > j) {
            return 0;
        }
        if (f[i][j] != -1) {
            return f[i][j];
        }
        // cout << i << " " << j << " " << f[i][j] << endl;
        int maxScore = 0;
        if (s[i] == s[j]) {
            maxScore = dp(s, i + 1, j - 1) + 2;
            if (maxScore == j - i + 1) {
                path[i][j] = {i, j};
            } else {
                maxScore = 0;
            }
        }
        int tmp = dp(s, i + 1, j);
        if (tmp > maxScore) {
            maxScore = tmp;
            path[i][j] = path[i + 1][j];
        }
        tmp = dp(s, i, j - 1);
        if (tmp > maxScore) {
            maxScore = tmp;
            path[i][j] = path[i][j - 1];
        }
        f[i][j] = maxScore;
        return maxScore;
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            vector<int> a;
            vector<pair<int, int>> b;
            for (int j = 0; j < s.size(); j++) {
                a.push_back(-1);
                b.push_back({0, 0});
            }
            f.push_back(a);
            path.push_back(b);
        }
        dp(s, 0, s.size() - 1);
        auto p = path[0][s.size() - 1];
        return s.substr(p.first, p.second - p.first + 1);
    }
};
// @lc code=end
