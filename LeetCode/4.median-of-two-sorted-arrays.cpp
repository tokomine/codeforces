#define INPUT "../../../../LeetCode/test_case.txt"

#include <optional>
#include <vector>

#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
  public:
    int findLessThanCount(vector<int>& nums, int x, int l, int r) {
        int mid = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (nums[mid] >= x) {
            return mid;
        } else {
            return mid + 1;
        }
    }

    int findGreaterThanCount(vector<int>& nums, int x, int l, int r) {
        int mid = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (nums[mid] <= x) {
            return nums.size() - mid - 1;
        } else {
            return nums.size() - mid;
        }
    }

    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() && nums2.empty()) {
            return 0;
        }
        if (nums1.empty()) {
            return nums2[k - 1];
        }
        if (nums2.empty()) {
            return nums1[k - 1];
        }

        int l = 0;
        int r = nums1.size() - 1;
        int n = nums1.size() + nums2.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            int lessThanCount = findLessThanCount(nums2, nums1[mid], 0, nums2.size() - 1) + mid;
            int greaterThanCount =
                findGreaterThanCount(nums2, nums1[mid], 0, nums2.size() - 1) + nums1.size() - mid - 1;
            // cout << "findKth: " << nums1[mid] << " mid: " << mid << " l: " << l << " r: " << r
            //      << " lessThanCount: " << lessThanCount << " greaterThanCount: " << greaterThanCount << endl;
            if (lessThanCount > k - 1) {
                r = mid - 1;
            } else if (greaterThanCount > n - k) {
                l = mid + 1;
            } else {
                return nums1[mid];
            }
        }
        // max int
        return 0x7fffffff;
    }
    int findTarget(vector<int>& nums1, vector<int>& nums2, int k) {
        auto value = findKth(nums1, nums2, k);
        // cout << "find target value1: " << value << " k: " << k << endl;
        if (value != 0x7fffffff) {
            return value;
        }
        value = findKth(nums2, nums1, k);
        // cout << "find target value2: " << value << " k: " << k << endl;
        return value;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, r1 = nums1.size();
        int l2 = 0, r2 = nums2.size();
        int n = nums1.size() + nums2.size();
        int targetK = 0;
        int targetK2 = 0;
        if (n % 2 == 0) {
            targetK = n / 2;
            int value1 = findTarget(nums1, nums2, targetK);
            // cout << "target1: " << targetK << " value: " << value1 << endl;

            targetK2 = targetK + 1;
            int value2 = findTarget(nums1, nums2, targetK2);
            // cout << "target2: " << targetK2 << " value: " << value2 << endl;

            return (value1 + value2) / 2.0;
        } else {
            targetK = n / 2 + 1;
            int value = findTarget(nums1, nums2, targetK);
            // cout << "target: " << targetK << " value: " << value << endl;

            return value;
        }
    }
};
// @lc code=end
