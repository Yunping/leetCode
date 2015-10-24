/*
Problem: Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/24/2015
Difficulty: *
Review: *
Solution: two pointers
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *to_delete = &dummy;
        int i = 0;
        while (p) {
            if (i++ > n)
                to_delete = to_delete->next;
            p = p->next;
        }
        
        if (i > n) {
            ListNode *next = to_delete->next->next;
            delete to_delete->next;
            to_delete->next = next;
        }
        
        return dummy.next;
    }
};