/*
Problem: Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: **^
Review: ***^
Solution:
    (My Own) Time O(n) Space O(1)
    1. Set a fast pointer (2 nodes per step) and a slow pointer (1 node per step).
    2. Move these two pointer from head until the fast pointer reaches the end. At this time, the slow pointer
       must point to the middle of the list. Split the list (head->end) into two lists: head->fast_end, slow->end
    3. reverse the list (slow->end)
    4. merge the two lists.
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
    ListNode *reverse(ListNode *head) {
        ListNode *p = head;
        ListNode *prev = 0;
        
        while (p) {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        
        return prev;
    }
    
public:
    // my solution
    void reorderList(ListNode *head) {
        if (!head) return;
        
        // split the lists by the middle node.
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* fast_end = 0;
        while (fast) {
            fast_end = slow;
            slow = slow->next;
            fast = fast->next ? fast->next->next : 0;
        }
        
        // reverse slow list
        slow = reverse(slow);
        
        // merge slow and fast
        fast = head;
        fast_end->next = 0;
        
        if (fast != slow) {
            while (fast && slow) {
                ListNode* fast_next = fast->next;
                ListNode* slow_next = slow->next;
                fast->next = slow;
                slow->next = fast_next;
                fast = fast_next;
                slow = slow_next;
            }
        }
    }
};