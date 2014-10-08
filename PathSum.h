/*
Problem: Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: *^
Review: **
Solution: (My Own) DFS.
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        return hasPathSum_dfs(root, sum, 0);
    }

private:
    bool hasPathSum_dfs(TreeNode *root, int sum, int cur) {
        cur += root->val;
        if (!root->left && !root->right)
            return (cur == sum);
            
        bool ret = false;
        if (root->left)
            ret = hasPathSum_dfs(root->left, sum, cur);
        if (!ret && root->right)
            ret = hasPathSum_dfs(root->right, sum, cur);
            
        return ret;
    }
};