/*
Problem: Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Source: https://oj.leetcode.com/problems/reverse-nodes-in-k-group/

Author: Yunping
Date: 08/01/2014
Difficulty: **
Review: ***
Solution: A good exercise for lists.

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k <= 1) return head;
        
        ListNode *p1 = head;
        ListNode *prev = 0;
        ListNode *newHead = head;
        while (p1) {
            ListNode *p2 = nodeBehindK(p1, k);
            ListNode *next = 0;
            if (!p2) {
                if (prev)
                    prev->next = p1;
                break;
            } else {
                if (prev)
                    prev->next = p2;
                next = p2->next;
                prev = p1;
                reverse(p1, p2);
                p1 = next;
                if (newHead == head)
                    newHead = p2;
            }
        }
        
        return newHead;
    }

private:
    // get the node behind k steps to p1
    ListNode *nodeBehindK(ListNode *p1, int k) {
        ListNode *p2 = p1;
        while (k > 1 && p2) {
            p2 = p2->next;
            --k;
        }
        
        return p2;
    }
    
    // reverse list from p1 to p2.
    void reverse(ListNode *p1, ListNode *p2) {
        ListNode *prev = 0;
        while (p1 != p2) {
            ListNode *next = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = next;
        }
        
        p2->next = prev;
    }
};