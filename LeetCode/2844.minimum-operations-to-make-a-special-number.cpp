#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2844 lang=cpp
 *
 * [2844] Minimum Operations to Make a Special Number
 */

// @lc code=start
class Solution {
  public:
    int goTarget(string num, char a, char b) {
        int cnt = 0;
        int finded = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            if (finded == 0) {
                if (num[i] != b) {
                    cnt++;
                } else {
                    finded = 1;
                }
            } else if (finded == 1) {
                if (num[i] != a) {
                    cnt++;
                } else {
                    finded = 2;
                }
            } else {
                break;
            }
        }
        if (finded != 2) {
            return num.size();
        }
        return cnt;
    }
    int goZero(string num) {
        bool hasZero = false;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '0') {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            return num.size() - 1;
        } else {
            return num.size();
        }
    }
    int minimumOperations(string num) {
        int best = num.size();
        int cnt;
        cnt = goTarget(num, '0', '0');
        best = min(best, cnt);
        cnt = goTarget(num, '2', '5');
        best = min(best, cnt);
        cnt = goTarget(num, '5', '0');
        best = min(best, cnt);
        cnt = goTarget(num, '7', '5');
        best = min(best, cnt);
        cnt = goZero(num);
        best = min(best, cnt);
        return best;
    }
};
// @lc code=end
