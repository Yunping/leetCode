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

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/21/2015
Difficulty: ***
Review: **^
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
private:
    // revert k nodes from head. return new head and next head.
    pair<ListNode*, ListNode*> reverseKNodes(ListNode *head, int k) {
        pair<ListNode*, ListNode*> ret;
        
        // check if there is enough nodes left.
        int totalCount = 0;
        ListNode *p = head;
        while (p) {
            if (++totalCount >= k)
                break;
            p = p->next;
        }
        if (totalCount < k) {
            ret.first = head;
            ret.second = 0;
            return ret;
        }
        
        // reverse k nodes
        ListNode *prev = 0, *cur = head;
        int count = 0;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            if (++count == k)
                break;
        }
        
        ret.first = prev;
        ret.second = cur;
        
        return ret;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curHead = head;
        ListNode *prevTail = &dummy;
        while (curHead) {
            pair<ListNode*, ListNode*> heads = reverseKNodes(curHead, k);
            ListNode* reversedTail = curHead;
            ListNode* reversedHead = heads.first;
            prevTail->next = reversedHead;
            prevTail = reversedTail;
            curHead = heads.second;
        }
        
        return dummy.next;
    }
};