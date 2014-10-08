/*
Problem: Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/04/2014
Difficulty: *
Review: **
Solution: (My own) DP: paths count from (0,0) to (i, j): d[i][j] = d[i-1][j] + d[i][j-1]
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        
        // DP: d[i][j] = d[i-1][j] + d[i][j-1]
        vector<vector<int> > d(m, vector<int>(n, 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!i || !j)
                    d[i][j] = 1;
                else
                    d[i][j] = d[i-1][j] + d[i][j-1];
            }
        }
        
        return d[m-1][n-1];
    }
};