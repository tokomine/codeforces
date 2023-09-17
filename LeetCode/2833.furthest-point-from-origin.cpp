#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2833 lang=cpp
 *
 * [2833] Furthest Point From Origin
 */

// @lc code=start
class Solution {
  public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, T = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'L') {
                L++;
            }
            if (moves[i] == 'R') {
                R++;
            }
            if (moves[i] == '_') {
                T++;
            }
        }
        return max(L - R + T, R - L + T);
    }
};
// @lc code=end
