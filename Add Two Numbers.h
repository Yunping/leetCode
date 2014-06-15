/*
Problem: https://oj.leetcode.com/problems/add-two-numbers/
Date: 06/15/2014
Difficulty: **
Note: 一次做出。但代码写的不够简洁。后来看了别人的解法后，简化代码，将两个链表的循环合并成一个
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *l = 0;
        ListNode *prev = 0;
        int carry = 0;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 || p2) {
            int sum = carry;
            if (p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            carry = sum / 10;
            ListNode *p = new ListNode(sum % 10);
            if (!prev)
                l = p;
            else
                prev->next = p;
            prev = p;
        }
        
        if (carry) {
            prev->next = new ListNode(carry);
        }
        
        return l;
    }
};