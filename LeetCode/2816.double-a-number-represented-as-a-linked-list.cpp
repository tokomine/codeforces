#include "leetcode-definition.h"
#include "leetcode-types.h"

/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
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
    ListNode* revertIt(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* p = revertIt(head);
        head = p;
        bool upper = false;

        while (p) {
            p->val *= 2;
            if (upper) {
                p->val += 1;
            }
            if (p->val >= 10) {
                p->val -= 10;
                upper = true;
            } else {
                upper = false;
            }
            p = p->next;
        }
        ListNode* result = revertIt(head);
        if (upper) {
            ListNode* tmp = new ListNode(1);
            tmp->next = result;
            result = tmp;
        }
        return result;
    }
};
// @lc code=end
