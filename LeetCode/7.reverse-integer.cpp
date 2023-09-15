#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
  public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 10 && x > -10) {
            return x;
        }
        long long L = -1 * (1LL << 31);
        long long R = (1LL << 31) - 1;

        if (x < 0) {
            isNeg = true;
            if (-1 * (long long)x > R) {
                // cout << "x: " << x << endl;
                return 0;
            }
            x = -x;
        }

        long long rev = 0;

        // cout << L << " " << R << " x:" << x << endl;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
            // cout << "rev: " << rev << endl;
        }
        if (isNeg) {
            rev = -rev;
        }
        if (rev < L || rev > R) {
            // cout << "rev: " << rev << endl;
            return 0;
        }
        // cout << "end: " << rev << endl;

        return rev;
    }
};
// @lc code=end
