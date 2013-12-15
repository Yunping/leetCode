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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *l = head;
        ListNode *r = 0;
        ListNode *previous = 0;
        ListNode *next = 0;
        while (l) {
            r = l->next;
            if (r) {
                if (previous)
                    previous->next = r;
                next = r->next;
                l->next = next;
                r->next = l;
                if (l == head)
                    head = r;
                previous = l;
            } else
                break;
            
            l = next;
        }
        
        return head;
    }
};