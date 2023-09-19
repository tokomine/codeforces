#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2806 lang=cpp
 *
 * [2806] Account Balance After Rounded Purchase
 */

// @lc code=start
class Solution {
  public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if (purchaseAmount % 10 >= 5) {
            purchaseAmount = purchaseAmount - purchaseAmount % 10 + 10;
        } else {
            purchaseAmount = purchaseAmount - purchaseAmount % 10;
        }
        return 100 - purchaseAmount;
    }
};
// @lc code=end
