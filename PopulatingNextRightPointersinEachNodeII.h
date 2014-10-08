/*
Problem: Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
    
=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: ***
Review: ***^
Solution: (My Own)
    the key to the problem is implement a method to get the next valid (non-null) child in current level.
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    TreeLinkNode *nextValidChild(TreeLinkNode *node) {
        TreeLinkNode *ret = 0;
        while (!ret && node) {
            ret = node->left ? node->left : node->right;
            node = node->next;
        }
        return ret;
    }
    
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        TreeLinkNode *curNode = root;
        curNode->next = 0;
        TreeLinkNode *nextLevelNode = curNode->left ? curNode->left : curNode->right;
        
        while (nextLevelNode) {
            if (curNode->left) {
                curNode->left->next = curNode->right;
                if (!curNode->right)
                    curNode->left->next = nextValidChild(curNode->next);
                else
                    curNode->right->next = nextValidChild(curNode->next);
            } else if (curNode->right)
                curNode->right->next = nextValidChild(curNode->next);
            
            if (!curNode->next) {
                curNode = nextLevelNode;
                nextLevelNode = nextValidChild(curNode);
            } else
                curNode = curNode->next;
        }
    }
};