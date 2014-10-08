/*
Problem: 
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

==============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/07/2014
Difficulty: ***
Review: ****
Solution: (My Own)
    1. Recursively calculate the maximum sum path which STARTS from current root. say it is 'max_sum_to(node)'
    2. The maximum sum path which CONTAINS the current root. say it is 'max_sum(node)'. then:
       max_sum(node) = node->val + max(0, max_sum_to(node->left)) + max(0, max_sum_to(node->right))
    3. The maxPathSum = max(max_sum(node_i))
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
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        
        int left_max_sum = 0, right_max_sum = 0;
        int max_sum = INT_MIN;
        maxPathToNode(root, max_sum);
        
        return max_sum;
    }
    
private:
    // maximum sum path which starts from current root
    int maxPathToNode(TreeNode *root, int &max_sum) {
        int left_max_sum = 0;
        if (root->left)
            left_max_sum = maxPathToNode(root->left, max_sum);
        
        int right_max_sum = 0;
        if (root->right)
            right_max_sum = maxPathToNode(root->right, max_sum);
        
        // calculate the max path sum which goes through current root node.
        max_sum = max(max_sum, max(left_max_sum, 0) + max(right_max_sum, 0) + root->val);
        
        // calculate the max path sum which starts from root.
        int max_to_child = max(max(left_max_sum, right_max_sum), 0);
        int max_to_cur = max_to_child + root->val;
        
        return max_to_cur;
    }
};