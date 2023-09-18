#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=2831 lang=cpp
 *
 * [2831] Find the Longest Equal Subarray
 */

// @lc code=start

class Segment {
  public:
    int l, r;
    int len;
    int num;
    Segment(int l, int r, int num) : l(l), r(r), num(num) { len = r - l + 1; }
    // operator <
    bool operator<(const Segment& s) const {
        if (num != s.num) {
            return num < s.num;
        }
        return l < s.l;
    }
    int distance(const Segment& s) const {
        if (num != s.num) {
            return INT_MAX;
        }
        if (l < s.l) {
            return s.l - r - 1;
        }
        return l - s.r - 1;
    }
};

class Solution {
  public:
    int findMaxLengthInEqualSegments(const vector<Segment>& segs, int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return segs[l].len;
        }
        int length = segs[l].len;
        int maxLength = length;
        int skip = 0;
        int leftPos = l;
        for (int i = l + 1; i <= r; i++) {
            int dist = segs[i].distance(segs[i - 1]);
            if (dist + skip <= k) {
                length += segs[i].len;
                skip += dist;
            } else {
                length += segs[i].len;
                skip += dist;
                while (skip > k) {
                    length -= segs[leftPos].len;
                    skip -= segs[leftPos].distance(segs[leftPos + 1]);
                    leftPos++;
                }
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        vector<Segment> segs;
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
                segs.emplace_back(l, i, nums[i]);
                l = i + 1;
            }
        }
        sort(segs.begin(), segs.end());
        int maxLength = 0;
        int leftPos = 0;
        int currentNum = -1;
        if (segs.size() == 1) {
            return segs[0].len;
        }
        for (int i = 1; i < segs.size(); i++) {
            if (i == segs.size() - 1 || segs[i + 1].num != segs[i].num) {
                int length = findMaxLengthInEqualSegments(segs, leftPos, i, k);
                maxLength = max(maxLength, length);
                leftPos = i + 1;
            }
        }
        return maxLength;
    }
};
// @lc code=end
