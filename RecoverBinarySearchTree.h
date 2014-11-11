/*
Problem: Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/27/2014
Difficulty: ***
Review: ****
Solution: (My Own) Space: O(n) Time: O(n)
    1. inorder traversal to get all nodes
    2. iterate from left to right to find the first incorrect node
    3. iterate from right to left to find the second incorrect node
    4. swap values of these two nodes
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
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        
        pair<TreeNode*, TreeNode*> incorrectNodes;
        int n = nodes.size();
        
        // left to right find the first incorrect node
        for (int i = 0; i < n-1; ++i) {
            if (nodes[i]->val > nodes[i+1]->val) {
                incorrectNodes.first = nodes[i];
                break;
            }
        }
        
        // right to left find the second incorrect node
        for (int i = n-1; i > 0; --i) {
            if (nodes[i]->val < nodes[i-1]->val) {
                incorrectNodes.second = nodes[i];
                break;
            }
        }
        
        swap(incorrectNodes.first->val, incorrectNodes.second->val);
    }
    
    void inorder(TreeNode *root, vector<TreeNode*>& nodes) {
        if (root) {
            inorder(root->left, nodes);
            nodes.push_back(root);
            inorder(root->right, nodes);
        }
    }
};