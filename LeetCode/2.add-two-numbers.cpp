#include <cstddef>

#include "leetcode-definition.h"

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        int plus = 0;
        ListNode* p = head;
        while (l1 != nullptr || l2 != nullptr || plus > 0) {
            if (head == nullptr) {
                head = new ListNode(0);
                p = head;
            } else {
                p->next = new ListNode(0);
                p = p->next;
            }
            if (l1 != nullptr) {
                p->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                p->val += l2->val;
                l2 = l2->next;
            }
            p->val += plus;
            plus = p->val / 10;
            p->val %= 10;
        }
        return head;
    }
};
// @lc code=end
