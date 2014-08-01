/*
Problem: Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

Source: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

Author: Yunping, qufang83@gmail.com
Date: Aug 1, 2014
Difficulty: *
Review: ***
Solution: No need to use too many vars.

*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && A[i] == A[i-1])
                continue;
            A[j++] = A[i];
        }
        
        return j;
    }
};