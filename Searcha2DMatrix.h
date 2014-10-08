/*
Problem: Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/08/2014
Difficulty: *^
Review **
Solution: (My Own)
    As the first integer of each row is greater than the last integer of the previous row,
    we can treat the matrix as a sorted array. So use binary-search.
    * Note: The loop termination condition in a binary-search is (low <= high), not (low < high)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int total = m * n;
        int low = 0, high = total - 1;
        while (high >= low) {
            int mid = low + (high - low)/2;
            int mid_value = matrix[mid/n][mid%n];
            if (mid_value == target)
                return true;
            if (mid_value > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return false;
    }
};