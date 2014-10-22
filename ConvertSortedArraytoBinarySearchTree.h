/*
Problem: Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/13/2014
Difficulty: ^
Review: *
Solution:...
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size()-1);   
    }
    
private:
    TreeNode *sortedArrayToBST(vector<int> &num, int from, int to) {
        if (from <= to) {
            int mid = (from + to) / 2;
            TreeNode *root = new TreeNode(num[mid]);
            root->left = sortedArrayToBST(num, from, mid-1);
            root->right = sortedArrayToBST(num, mid+1, to);
            return root;
        }
        
        return 0;
    }
};