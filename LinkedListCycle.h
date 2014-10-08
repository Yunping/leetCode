/*
Problem: Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

==================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: *
Review: *
Solution: (My Own) fast&slow pointer.
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        
        while (p1 && p2) {
            if (p1 == p2)
                return true;
            p1 = p1->next;
            p2 = p2->next ? p2->next->next : 0;
        }
        
        return false;
    }
};