/*
Problem: Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/07/2014
Difficulty: ****
Review: **
Solution:
    * This problem is the same with a problem in 'Cracking the code interview' *
    Fast & Slow pointer
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return 0;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while (p1 && p2) {
            p1 = p1->next;
            p2 = p2->next ? p2->next->next : 0;
            
            if (p1 == p2)
                break;
        }
        
        if (!p2) return 0;
        
        p2 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};