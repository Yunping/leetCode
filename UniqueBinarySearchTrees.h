/*
Problem: Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: ***
Review: ****
Solution: (My Own) Recursion calculate the number of possible BS trees between l to r.
*/
class Solution {    
public:
    // return the number of possible BS trees between l to r.
    int numTrees(int l, int r) {
        if (l >= r) return 1;
        
        int curSum = 0;
        for (int root = l; root <= r; ++root) {
            int leftSum = numTrees(l, root-1);
            int rightSum = numTrees(root+1, r);
            curSum += (leftSum * rightSum);
        }
        
        return curSum;
    }
    
    int numTrees(int n) {
        return numTrees(1, n);
    }
};