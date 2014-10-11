/*
Problem: Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

===========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: **
Review: ***
Solution: (My Own)
    Similiar with array partition.
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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return 0;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        
        ListNode *pos = &dummy;
        ListNode *p = head;
        ListNode *prev_p = &dummy;
        while (p) {
            ListNode *next_p = p->next;
            if (p->val < x) {
                if (pos->next != p) {
                    // insert p after pos
                    ListNode *next_pos = pos->next;
                    pos->next = p;
                    p->next = next_pos;
                    prev_p->next = next_p;
                } else {
                    // pos->next is p, no need to insert, just
                    // update the pos and prev_p.
                    pos = p;
                    prev_p = p;
                    p = next_p;
                }
            } else {
                // ignore p if p->val is >= x
                prev_p = p;
                p = next_p;
            }
        }
        
        return dummy.next;
    }
};