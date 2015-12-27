/*
Problem: Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/08/2015
Difficulty: **
Review: **^
Solution: Use a minimum-heap
Notes:
1. By default: priority-queue is maximum-heap.
2. Function object

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
    struct ListNodeCmp {
        bool operator() (const ListNode* l, const ListNode* r){
            return (l->val > r->val);
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        
        // initialize min heap
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> q;
        for (ListNode *list : lists) {
            if (list)
                q.push(list);
        }
        
        // generate sorted list via the heap.
        while (!q.empty()) {
            ListNode *minNode = q.top();
            q.pop();
            if (minNode->next)
                q.push(minNode->next);
            ListNode *node = new ListNode(minNode->val);
            p->next = node;
            p = node;
        }
        
        return dummy.next;
    }
};