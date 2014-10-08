/*
Problem: Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

================================================================================

Author: Yunping,
Date: 10/07/2014
Difficulty: *^
Review: ***^
Solution: (My Own)
    Use a 'dups' to record number of dups. This problem could be a good coding practice.
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        int dups = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || A[i] != A[i-1]) {
                dups = 0;
                A[j++] = A[i];
            }
            else if (++dups < 2) {
                A[j++] = A[i];
            }
        }
        
        return j;
    }
};