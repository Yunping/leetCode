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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k <= 0) return head;
        
        ListNode *t = head;
        ListNode *from = head;
        ListNode *to = 0;
        ListNode *previousTo = 0;
        ListNode *next = 0;
        int size = 0;
        while (t) {
            next = t->next;
            if (size == 0)
                from = t;
            if (++size == k) {
                to = t;
                // Revert from - to
                ListNode *p = 0;
                ListNode *c = from;
                ListNode *n = 0;
                while (c != to) {
                    n = c->next;
                    c->next = p;
                    p = c;
                    c = n;
                }
                if (previousTo)
                    previousTo->next = to;
                to->next = p;
                from->next = next;
                if (from == head)
                    head = to;
                size = 0;
                previousTo = from;
            }
            t = next;
        }
        
        return head;
    }
};