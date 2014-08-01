/*
Problem: Remove Element
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Source: https://oj.leetcode.com/problems/remove-element/

Author: Yunping, qufang83@gmail.com
Date: Aug 1, 2014
Difficulty: *^
Review: ***
Solution: Updated. Use two indexes.

*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!A || n <= 0) return 0;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j] != elem)
                A[i++] = A[j];
        }
        
        return i;
    }
};