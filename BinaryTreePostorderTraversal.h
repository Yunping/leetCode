/*
Problem: Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

======================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: **
Review: ***
Solution: (My Own) Recursion or Iteration
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        postorder(root, ret);
        
        return ret;
    }
    
private:
    void postorder_rec(TreeNode* root, vector<int> &ret) {
        if (root) {
            postorder_rec(root->left, ret);
            postorder_rec(root->right, ret);
            ret.push_back(root->val);
        }
    }
    
    void postorder(TreeNode* root, vector<int> &ret) {
        if (root) {
            stack<TreeNode*> s;
            s.push(root);
            TreeNode* q = 0;
            while (!s.empty()) {
                TreeNode* p = s.top();
                TreeNode* child = p->right ? p->right : p->left;
                if (!child || (q == child)) {
                    // q == child means that it is a back process
                    // finish the node and pop the stack
                    q = p;
                    ret.push_back(p->val);
                    s.pop();
                } else {
                    if (p->right)
                        s.push(p->right);
                    if (p->left)
                        s.push(p->left);
                }
            }
        }
    }
};