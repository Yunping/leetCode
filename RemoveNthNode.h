/*
Problem: Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.


Date: 07/29/2014
Difficulty: *^
Review: **^
Note: Not difficulty. 
- Get the node before the to be deleted node.
- Care the case that the to be deleted node is the head node.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n <= 0) return head;
        
        ListNode *p1 = head;
        int steps = 0;
        for (; steps < n && p1; ++steps)
            p1 = p1->next;
            
        if (steps == n) {
            ListNode *p2 = 0;
            while (p1) {
                p2 = p2 ? p2->next : head;
                p1 = p1->next;
            }
            
            ListNode *toDelete = 0;
            if (!p2) {
                toDelete = head;
                head = head->next;
            } else {
                toDelete = p2->next;
                p2->next = toDelete->next;
            }
            
            delete toDelete;
        }
        
        return head;
    }
};