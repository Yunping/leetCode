/*
Problem: Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: **
Review: ***^
Solution: (My Own) 
    RECURSION
    *NOTE*: 易出错的点：不仅要判断左右子树和父节点的关系，还要判断与祖先节点的关系。
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
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
private:
    bool isValidBST(TreeNode *root, int min_v, int max_v) {
        if (!root)
            return true;
        if (root->val >= max_v || root->val <= min_v)
            return false;
        if (root->left && (root->left->val >= root->val))
            return false;
        if (root->right && (root->right->val <= root->val))
            return false;
        
        return (isValidBST(root->left, min_v, min(max_v, root->val)) && isValidBST(root->right, max(min_v, root->val), max_v));
    }
};