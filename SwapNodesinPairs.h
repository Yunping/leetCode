/*
Problem: Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Source: https://oj.leetcode.com/problems/swap-nodes-in-pairs/

Author: Yunping
Date: 07/31/2014
Difficulty: **^
Review: ***
Solution: Not a hard problem. But it is mistakable and need to consider all cases.
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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        head = p2;
        
        while (p2) {
            ListNode *nextP1 = p2->next;
            p1->next = (nextP1 && nextP1->next) ? nextP1->next : nextP1;
            p2->next = p1;
            
            p1 = nextP1;
            p2 = nextP1 ? nextP1->next : 0;
        }
        
        return head;
    }
};