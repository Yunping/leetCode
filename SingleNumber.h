/*
Problem: Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/08/2014
Difficulty: *
Review: **
Solution: (My Own)
    xor all items in the array.
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for (int i = 0; i < n; ++i)
            ret ^= A[i];
        
        return ret;
    }
};