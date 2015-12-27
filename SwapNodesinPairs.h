/*
Problem: Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/08/2015
Difficulty: *
Review: *^
Solution: Two pointers
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *p1 = head, *p2 = head->next;
        while (p1 && p2) {
            ListNode *next = p2->next;
            prev->next = p2;
            p2->next = p1;
            p1->next = next;
            
            prev = p1;
            p1 = next;
            p2 = p1 ? p1->next : 0;
        }
        
        return dummy.next;
    }
};