/*
Problem: Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/07/2014
Difficulty: **^
Review: **
Solution:
    此题与剑指offer中一道题相同。在递归过程中算出树的高度，便于父节点快速判断平衡条件，
    避免重复递归。
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
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int height;
        return isBalanced(root, height);
    }
    
private:
    bool isBalanced(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int left, right;
        if (isBalanced(root->left, left) && isBalanced(root->right, right)) {
            height = max(left, right) + 1;
            return (abs(left-right) <= 1);
        }
        
        return false; 
    }
};