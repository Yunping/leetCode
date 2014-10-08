/*
Problem: Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: *^
Review: **
Solution: (My Own) DFS
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        if (!root) return ret;
        
        vector<int> temp;
        pathSum_dfs(root, sum, 0, temp, ret);
        
        return ret;
    }
    
private:
    
    void pathSum_dfs(TreeNode *root, int sum, int cur, vector<int> &result, vector<vector<int> >& ret) {
        cur += root->val;
        result.push_back(root->val);
        if (!root->left && !root->right) {
            if (cur == sum)
                ret.push_back(result);
        } else {
            if (root->left)
                pathSum_dfs(root->left, sum, cur, result, ret);
            if (root->right)
                pathSum_dfs(root->right, sum, cur, result, ret);
        }
        result.pop_back();
    }
};