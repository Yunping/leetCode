/*
Problem: Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/03/2014
Difficulty: *^
Review: **^
Solution: 
(My own)
DP: d[i][j] = min(d[i-1][j], d[i][j-1]) + grid[i][j]
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        vector<vector<int> > d(m, vector<int>(n, 0));
        
        // d[i][j] = min(d[i-1][j], d[i][j-1]) + grid[i][j]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (i && j)
                    d[i][j] = min(d[i-1][j], d[i][j-1]) + grid[i][j];
                else if (i)
                    d[i][j] = d[i-1][j] + grid[i][j];
                else if (j)
                    d[i][j] = d[i][j-1] + grid[i][j];
                else
                    d[i][j] = grid[i][j];
        }
        
        return d[m-1][n-1];
    }
};