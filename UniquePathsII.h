/*
Problem: Unique Paths II
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

==============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/04/2014
Difficulty: **
Review: ***
Solution: (My own)
    method1: DP
    method2: DFS
*/
class Solution {
public:
    // method 1: DP
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid[0].size();
        if (!n) return 0;
        
        vector<vector<int> > d(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j])
                    d[i][j] = 0;
                else if (!i && !j)
                    d[i][j] = 1;
                else
                    d[i][j] = (i ? d[i-1][j] : 0) + (j ? d[i][j-1] : 0);
            }
        }
        
        return d[m-1][n-1];
    }
    
    // method 2: DFS. (Time Limit Exceeded)
    int uniquePathsWithObstacles_2(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid[0].size();
        if (!n) return 0;
        int count = 0;
        doUniquePaths(obstacleGrid, m, n, 0, 0, count);
        
        return count;
    }
    
    void doUniquePaths(vector<vector<int> > &obstacleGrid, int m, int n, int x, int y, int &count) {
        if (obstacleGrid[x][y] == 0) {
            if (x == m-1 && y == n-1) {
                ++count;
                return;
            }
            if (x < m-1)
                doUniquePaths(obstacleGrid, m, n, x+1, y, count);
            if (y < n-1)
                doUniquePaths(obstacleGrid, m, n, x, y+1, count);
        }
    }
};