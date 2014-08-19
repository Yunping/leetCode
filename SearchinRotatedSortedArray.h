/*
Problem: Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

==========================================================================

Author: Yunping, qufang83@gmail.com
Date: 08/19/2014
Difficulty: **
Review: ***
Solution: 
Compare A[m] with A[l], if A[m] is not less than A[l], then A[m] must fall in the first half of the sorted array; else, A[m] must fall in the second half.
If the Array is rotated zero time (not rotated), it is a special case of case 1.

*/
class Solution {
public:
    int search(int A[], int n, int target) {
        if (!A || n <= 0) return -1;
        
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (A[m] == target)
                return m;
                
            if (A[m] >= A[l]) { // m falls in the first half
                if (A[m] > target && A[l] <= target)
                    r = m - 1;
                else
                    l = m + 1;
            } else {    // m falls in the second half
                if (target > A[m] && target <= A[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        
        return -1;
    }
};