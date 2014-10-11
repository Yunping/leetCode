/*
Problem: Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

==========================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/11/2014
Difficulty: **
Review: ****
Solution: Iteration.
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                // push p to stack along left branch until null for future use.
                s.push(p);
                p = p->left;
            } else {
                // pop stack: left and mid have been done, push right child
                p = s.top();
                s.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }
        
        return ret;
    }
};