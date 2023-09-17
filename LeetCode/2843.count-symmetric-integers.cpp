#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2843 lang=cpp
 *
 * [2843]   Count Symmetric Integers
 */

// @lc code=start
class Solution {
  public:
    bool isSame(int x) {
        int d = 0;
        vector<int> v;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        if (v.size() % 2 == 1) {
            return false;
        }
        int suma = 0, sumb = 0;
        for (int i = 0; i < v.size() / 2; i++) {
            suma += v[i];
            sumb += v[v.size() - 1 - i];
        }
        return suma == sumb;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (isSame(i)) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
