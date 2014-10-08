/*
Problem: Populating Next Right Pointers in Each Node
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
    
==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: **
Review: ***
Solution: (My Own)
    As the tree is a perfect binary tree, we don't need to use a queue. because the left 
    child's next node must be the right child, and the right child's next node must be 
    the left child of its parent's next node.
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        TreeLinkNode *curNode = root;
        curNode->next = 0;
        TreeLinkNode *nextLevelNode = curNode->left;
        while (nextLevelNode) {
            curNode->left->next = curNode->right;
            curNode->right->next = curNode->next ? curNode->next->left : 0;
            if (!curNode->next) {
                curNode = nextLevelNode;
                nextLevelNode = nextLevelNode->left;
            } else
                curNode = curNode->next;
        }
    }
};