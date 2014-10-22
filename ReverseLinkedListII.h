/*
Problem: Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/20/2014
Difficulty: **
Review: ***^
Solution:...
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        int count = 1;
        ListNode *p = head;
        ListNode *prev_m = &dummy;
        
        // find the mth node
        while (count < m) {
            prev_m = p;
            p = p->next;
            ++count;
        }
        
        // reverse from the mth node to nth node
        ListNode *prev_p = 0;
        ListNode *next_p = 0;
        while (count <= n) {
            next_p = p->next;
            p->next = prev_p;
            prev_p = p;
            p = next_p;
            ++count;
        }
        
        prev_m->next->next = p;
        prev_m->next = prev_p;
        
        return dummy.next;
    }
};