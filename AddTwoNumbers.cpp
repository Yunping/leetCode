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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *d1 = l1, *d2 = l2;
        ListNode *l3 = 0;
        ListNode *d3 = l3;
        
        int ten = 0;
        while (d1 != 0 || d2 != 0 || ten != 0) {
            int current = 0;
            if (d1 != 0) {
                current += d1->val;
                d1 = d1->next;
            }
            if (d2 != 0) {
                current += d2->val;
                d2 = d2->next;
            }
                
            current += ten;

            if (current >= 10) {
                current = current - 10;
                ten = 1;
            } else
                ten = 0;
                
            ListNode *newNode = new ListNode(current);
            if (l3 == 0)
                l3 = newNode;
            else
                d3->next = newNode;

            d3 = newNode;
        }
        
        return l3;
    }
};