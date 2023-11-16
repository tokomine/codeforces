#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto p = head;
        while (p) {
            auto q = p->next;
            if (!q) {
                break;
            }
            auto g = gcd(p->val, q->val);
            auto node = new ListNode(g);
            node->next = q;
            p->next = node;
            p = node->next;
        }
        return head;
    }
};
// @lc code=end
