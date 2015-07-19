/*
Problem: Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 1/24/2015
Difficulty: *^
Review: **
Solution:
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return 0;
        // calculate the length of the two lists
        int len1 = 0;
        int len2 = 0;
        ListNode *p1 = headA;
        while (p1) {
            ++len1;
            if (!p1->next)
                break;
            p1 = p1->next;
        }
        
        ListNode *p2 = headB;
        while (p2) {
            ++len2;
            if (!p2->next)
                break;
            p2 = p2->next;
        }
        
        // if the tails of the two lists are different, then
        // they must have no intersection.
        if (p1 != p2) return 0;
        
        // move forward the longer list until the two lists have the 
        // same number of nodes left.
        int diff = len1 - len2;
        p1 = headA;
        p2 = headB;
        if (diff > 0) {
            while (diff > 0) {
                p1 = p1->next;
                --diff;
            }
        } else if (diff < 0) {
            while (diff < 0) {
                p2 = p2->next;
                ++diff;
            }
        }
        
        // move p1 and p2 until find the intersection.
        while (p1 != 0 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};