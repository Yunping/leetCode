/*
Problem: Insertion Sort List
Sort a linked list using insertion sort.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/08/2014
Difficulty: **^
Review: ***^
Solution: (My Own)
    链表的插入排序。
    很好的一个练习题目，虽然简单，但想要一次写好并不容易。
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
    // return the insert pos. the new node should be inserted after
    // this pos.
    ListNode* insertPos(ListNode* head, ListNode* tail, int value) {
        if (tail->val <= value)
            return tail;
        
        ListNode *p = head;
        ListNode *prev = 0;
        while (p) {
            // can't be "p->val >= value" because we should make sure
            // all values must be after the dummy node (INT_MIN)
            if (p->val > value)
                break;
            prev = p;
            
            if (p == tail)
                break;
            p = p->next;
        }
        
        return prev;
    }
    
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return 0;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        
        ListNode* next = 0;
        ListNode* sorted_tail = head;
        for (ListNode* cur = head->next; cur; cur = next) {
            next = cur->next;
            ListNode *pos = insertPos(&dummy, sorted_tail, cur->val);
            ListNode *after = pos->next;
            pos->next = cur;
            cur->next = after;
            if (pos == sorted_tail)
                sorted_tail = cur;
            sorted_tail->next = next;
            cur = next;
        }
        
        return dummy.next;
    }
};