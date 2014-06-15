/*
Date: 06/15/2014
Difficulty: *
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
    void doTraversal(vector<int> &paths, TreeNode *root) {
        if (root) {
            doTraversal(paths, root->left);
            doTraversal(paths, root->right);
            paths.push_back(root->val);
        }
    }
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        doTraversal(ret, root);
        return ret;
    }
};