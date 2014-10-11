/*
Problem: Unique Binary Search Trees II
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
============================================================================================

Author: Yunping,
Date: 10/09/2014
Difficulty: ***
Review: ****
Solution: (My Own)
    Recursively generate all possible BS trees if input is from l to r.
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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }

private:
    // return all possible BS trees if input is from l to r.
    vector<TreeNode *> generateTrees(int l, int r) {
        vector<TreeNode*> ret;
        if (l > r) {
            ret.push_back(0);
            return ret;
        }
        
        if (l == r) {
            ret.push_back(new TreeNode(l));
            return ret;
        }
        
        for (int root = l; root <= r; ++root) {
            vector<TreeNode*> leftSubTrees = generateTrees(l, root-1);
            vector<TreeNode*> rightSubTrees = generateTrees(root+1, r);
            for (auto left:leftSubTrees) {
                for (auto right:rightSubTrees) {
                    TreeNode *root_node = new TreeNode(root);
                    root_node->left = left;
                    root_node->right = right;
                    ret.push_back(root_node);
                }
            }
        }
        
        return ret;
    }
};