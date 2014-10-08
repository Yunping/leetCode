/*
Problem: Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/07/2014
Difficulty: *
Review: **
Solution: Recursion or Iteration
    * Very similiar with the problem 'Minimum Depth of Binary Tree'
      see: https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/.
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
    int maxDepth_1(TreeNode *root) {
        if (!root) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left, right) + 1;
    }
    
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        
        stack<pair<TreeNode*, int> > s;
        s.push(make_pair(root, 1));
        int ret = INT_MIN;
        while (!s.empty()) {
            auto cur = s.top().first;
            auto depth = s.top().second;
            s.pop();
            
            if (!cur->left && !cur->right)
                ret = max(ret, depth);
            if (cur->left)
                s.push(make_pair(cur->left, depth+1));
            if (cur->right)
                s.push(make_pair(cur->right, depth+1));
        }
        
        return ret;
    }
};