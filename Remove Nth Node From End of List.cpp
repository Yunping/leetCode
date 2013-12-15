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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *t = head;
        ListNode *l = 0, *m = head;
        int count = 0;
        while (t) {
            if (++count > n) {
                l = m;
                m = m->next;
            }
            t = t->next;
        }
        
        if (head == m)
            head = m->next;
        else
            l->next = m->next;
            
        return head;
    }
};