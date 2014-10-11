/*
Problem: Search in Rotated Sorted Array II
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/10/2014
Difficulty: ***
Review: ***^
Solution: (My Own)
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        return search(A, 0, n-1, target);
    }
    
private:
    bool binary_search(int A[], int l, int r, int target) {
        if (l > r) return false;
        int m = (l + r) / 2;
        if (A[m] == target)
            return true;
        
        if (A[m] < target)
            return binary_search(A, m+1, r, target);
        else
            return binary_search(A, l, m-1, target);
    }
    
    bool search(int A[], int l, int r, int target) {
        if (l > r) return false;
        
        int m = l + (r-l)/2;
        int mid = A[m];
        if (target ==  mid) return true;
        
        if (A[l] == A[r] && A[l] == mid) {
            // do a linear search.
            return search(A, l, m-1, target) || search(A, m+1, r, target);
        } else if (A[l] < A[r]) {
            // do a binary search
            return binary_search(A, l, r, target);
        } else {
            // A[l] >= A[r], the array must be rotated.
            if (mid > A[r]) {
                // mid > right, first half is longer
                if (target >= A[l] && target < mid) {
                    return search(A, l, m-1, target);
                } else
                    return search(A, m+1, r, target);
            } else {
                // mid <= right, second half is longer
                if (target > mid && target <= A[r])
                    return search(A, m+1, r, target);
                else
                    return search(A, l, m-1, target);
            }
        }
    }
};