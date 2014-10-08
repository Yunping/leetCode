/*
Problem: Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/07/2014
Difficulty: *^
Review: ***
Solution: 
    1. (My Own) Recursion.
    Note: if a node has only one child, we should ignore the null child and calculate 
    the min depth of the non-null child.
    
    2. (Refered to others) Iteration with a stack.
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

    // Recursion
    int minDepth_1(TreeNode *root) {
        if (!root) return 0;
        
        if (!root->left && !root->right)
            return 1;
        
        int left = root->left ? minDepth(root->left) : INT_MAX;
        int right = root->right ? minDepth(root->right) : INT_MAX;
        
        return min(left, right) + 1;
    }
    
    // 
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        
        if (!root->left && !root->right)
            return 1;
        
        int ret = INT_MAX;
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));
        while (!s.empty()) {
            TreeNode *cur = s.top().first;
            int depth = s.top().second;
            s.pop();
            
            // leave node. compare its depth with original one.
            if (!cur->left && !cur->right)
                ret = min(ret, depth);
            
            // stack the children with depths
            if (cur->left)
                s.push(make_pair(cur->left, depth + 1));
            
            if (cur->right)
                s.push(make_pair(cur->right, depth + 1));
        }
        
        return ret;
    }
};