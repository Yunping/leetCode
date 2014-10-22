/*
Problem: Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/13/2014
Difficulty: *^
Review: **
Solution: (My Own)
    Using fast/slow pointers to find the middle node of the sorted list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return 0;
        if (!head->next) return new TreeNode(head->val);
        
        ListNode *midNode = breakList(head);
        TreeNode *root = new TreeNode (midNode->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(midNode->next);
        
        return root;
    }
    
private:
    // break the list into two lists. return the middle node.
    ListNode *breakList(ListNode *head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *first_end = 0;
        while (p1 && p1->next) {
            first_end = p2;
            p1 = p1->next->next;
            p2 = p2->next;
        }
        first_end->next = 0;
        
        return p2;
    }
};