/*
Problem: Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

=========================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: *^
Review: ***
Solution: (My Own) Recursion or Iteration
    *NOTE* 迭代的顺序和递归刚好相反
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        preorder_rec(root, ret);
        
        return ret;
    }
    
private:
    void preorder_rec(TreeNode *root, vector<int> &ret) {
        if (root) {
            ret.push_back(root->val);
            preorder_rec(root->left, ret);
            preorder_rec(root->right, ret);
        }
    }
    
    void preorder(TreeNode *root, vector<int> &ret) {
        if (!root) return;
        
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            ret.push_back(p->val);
            
            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);
        }
    }
};