/*
Problem: Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

==============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/03/2014
Difficulty: *^
Review: ***
Solution: 
    S1: (My own)
    1. calculate the item count of the list.
    2. k = k % n, then find the last k items as the first k items in the rotated list.
    
    S2: (better)
    1. calculate the item count of the list
    2. k = k % n, then connect the tail of the list to the head. The list will be a circle.
    3. from the head, count n-k items. break the list here.
    
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
    // S1
    ListNode *rotateRight_1(ListNode *head, int k) {
        if (!head || !k) return head;
        
        int n = 0;
        ListNode *p = head;
        while (p) {
            ++n;
            p = p->next;
        }
        
        if (n == 1) return head;
        if (!(k %= n)) return head;
        
        ListNode *old_tail = 0;
        ListNode *new_head = 0;
        ListNode *new_tail = 0;
        p = head;
        int i = 0;
        while (p) {
            if (i < k-1)
                ++i;
            else {
                new_tail = new_head;
                new_head = new_head ? new_head->next : head;
            }
            
            old_tail = p;
            p = p->next;
        }
        
        new_tail->next = 0;
        old_tail->next = head;
        
        return new_head;
    }
    
    // S2
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !k) return head;
        
        int n = 0;
        ListNode *p = head;
        ListNode *tail = 0;
        while (p) {
            ++n;
            tail = p;
            p = p->next;
        }
        
        if (n == 1) return head;
        if (!(k %= n)) return head;
        
        tail->next = head;
        int advance = 1;
        p = head;
        while (advance < n - k) {
            p = p->next;
            ++advance;
        }
        
        ListNode *new_head = p->next;
        p->next = 0;
        
        return new_head;
    }
};