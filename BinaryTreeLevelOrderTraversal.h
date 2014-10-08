/*
Problem: Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

=====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/03/2014
Difficulty: **
Review: ****
Solution:
    - use a queue
    - record the last node of each level to know when the current level is completed.
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *prevNode = 0; // the last non-null node.
        TreeNode *lastNode = root;  // the last node in each level.
        vector<int> result;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            result.push_back(node->val);
            
            if (node->left) {
                q.push(node->left);
                prevNode = node->left;
            }
            
            if (node->right) {
                q.push(node->right);
                prevNode = node->right;
            }
            
            if (node == lastNode) {
                // this is the last node in current level. update results.
                // the prevNode is the last node of the next level...
                ret.push_back(result);
                result.clear();
                
                lastNode = prevNode;
            }
        }
        
        return ret;
    }
};