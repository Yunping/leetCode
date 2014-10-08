/*
Problem: Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/08/2014
Difficulty: **
Review: **^
Solution: (My Own)
    Recursion. (post-order-traversal)
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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumNumbers_recursive(root, 0, sum);
        
        return sum;
    }
    
private:
    void sumNumbers_recursive(TreeNode *root, int cur, int &sum) {
        if (root) {
            cur = 10 * cur + root->val;
            if (!root->left && !root->right) {
                sum += cur;
                return;
            }
            
            sumNumbers_recursive(root->left, cur, sum);
            sumNumbers_recursive(root->right, cur, sum);
        }
    }
};