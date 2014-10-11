/*
Problem: Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
             
=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: **^
Review: ***
Solution:
    1. Recursion (My Own)
    2. Iteration using a stack. (pre-order traversal)
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
    void flatten(TreeNode *root) {
        flattenTree2(root);
    }
    
private:
    // method1: Recursion
    void flattenTree(TreeNode *root) {
        if (!root) return;
        
        flattenTree(root->left);
        flattenTree(root->right);
        
        TreeNode *oldRight = root->right;
        root->right = root->left;
        root->left = 0;
        TreeNode* leftEnd = root;
        while (leftEnd->right)
            leftEnd = leftEnd->right;
            
        leftEnd->right = oldRight;
    }
    
    // method2: Iteration
    void flattenTree2(TreeNode *root) {
        if (!root) return;
        
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);
            p->left = 0;
            p->right = s.empty() ? 0 : s.top();
        }
    }
};