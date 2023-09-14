#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> v;
        while (x != 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i < v.size()/2; i++) {
            if(v[i] != v[v.size()-1-i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

