/*
Problem: Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/13/2014
Difficulty: ***
Review: ***^
Solution: (My Own)
    Almost the same as level-order traversal. Use a flag to indicate whether to
    insert result from the beginning or the ending.
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        bool forward = true;
        TreeNode *lastNode = root;
        TreeNode *nextLastNode = 0;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            
            result.insert(forward ? result.end() : result.begin(), node->val);
            
            if (node->left) {
                q.push(node->left);
                nextLastNode = node->left;
            }
            
            if (node->right) {
                q.push(node->right);
                nextLastNode = node->right;
            }
            
            if (node == lastNode) {
                ret.push_back(result);
                result.clear();
                lastNode = nextLastNode;
                nextLastNode = 0;
                forward = !forward;
            }
        }
        
        return ret;
    }
};