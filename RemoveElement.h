/*
Problem: Remove Element
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Source: https://oj.leetcode.com/problems/remove-element/

Author: Yunping, qufang83@gmail.com
Date: Aug 1, 2014
Difficulty: *^
Review: ***
Solution: Swap elem to the end of the array. Not a difficult problem. But not that easy to write correctly one time.

*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!A || n <= 0) return 0;
        
        int j = n-1;
        int i = 0;
        while (i <= j) {
            while (j >= i && A[j] == elem)
                --j;
            if (i > j)
                break;
                    
            if (A[i] == elem) {
                A[i] = A[j];
                A[j] = elem;
                --j;
            }
            
            ++i;
        }
        
        return j+1;
    }
};