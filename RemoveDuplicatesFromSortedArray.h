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
Solution: 

*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (!A || n <= 0) return 0;
        
        int cur = A[0];
        int src = 1;
        int dest = 1;
        
        while (src < n) {
            while (A[src] == cur && src < n)
                ++src;
            if (src == n)
                break;
            cur = A[src++];
            A[dest++] = cur;
        }
        
        return dest;
    }
};