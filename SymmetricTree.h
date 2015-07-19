/*
Problem: Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
   
================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/13/2014
Difficulty: **^
Review: ***
Solution:
    (My Own)
    1. Recursion
    2. Iteration. (Got from the recursion version)
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
private:
    bool isMirror(TreeNode *a, TreeNode *b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        
        if (a->val != b->val) return false;
        
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
    
public:
    // Method1: Recursion
    bool isSymmetric_rec(TreeNode *root) {
        if (!root) return true;
        
        return isMirror(root->left, root->right);
    }
    
    // Method2: Iteration
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        
        while (!s.empty()) {
            TreeNode *a = s.top();
            s.pop();
            TreeNode *b = s.top();
            s.pop();
            
            if (a && b) {
                if (a->val != b->val)
                    return false;
                s.push(a->left);
                s.push(b->right);
                s.push(a->right);
                s.push(b->left);
            } else if (a || b) {
                return false;
            }
        }
        
        return true;
    }
};