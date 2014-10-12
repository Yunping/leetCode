/*
Problem: Sort List
Sort a linked list in O(n log n) time using constant space complexity.

======================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/12/2014
Difficulty: **
Review: ***
Solution: (My Own)
    Using merge sort. (Merge sort a list didn't need extra space)
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
    
    // merge two sorted lists
    ListNode *merge(ListNode *p1, ListNode *p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        ListNode *head = 0;
        if (p1->val <= p2->val) {
            head = p1;
            head->next = merge(p1->next, p2);
        } else {
            head = p2;
            head->next = merge(p1, p2->next);
        }
        
        return head;
    }
    
public:
    // merge sort
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        
        // using fast/slow pointers to divide the list
        // into two lists.
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *prev_p2 = 0;
        while (p1) {
            prev_p2 = p2;
            p1 = p1->next ? p1->next->next : 0;
            p2 = p2->next;
        }
        
        // prev_p2 is the end of the first half.
        prev_p2->next = 0;
        
        p1 = sortList(head);
        p2 = sortList(p2);
        
        // merge the two sorted lists together.
        head = merge(p1, p2);
        
        return head;
        
    }
};