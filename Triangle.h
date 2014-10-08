/*
Problem: Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

========================================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: **
Review: ***^
Solution: (My Own)
          Method 1. DP. Time:O(N^2), Space:O(N^2).
          d[i][j] means the minimum sum from node j in row i.
          d[i][j] = min(d[i+1][j], d[i+1][j+1]) + triangle[i][j]
          
          Method 2. DP. The same as method1. But only use space O(N) because we don't have to 
          store data for all rows, we can store items of row i by overwriting items in row i+1.
          d[j] = min(d[j], d[j+1]) + triangle[i][j].
*/

class Solution {
public:
    // method 1. Time:O(N^2), Space:O(N^2).
    int minimumTotal_1(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<vector<int> > d(n, vector<int>(n, 0));
        
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                if (i == n-1)
                    d[i][j] = triangle[i][j];
                else
                    d[i][j] = min(d[i+1][j], d[i+1][j+1]) + triangle[i][j];
            }
        }
        
        return d[0][0];
    }
    
    // method 2. Time:O(N^2), Space:O(N).
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> d(n, 0);
        
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                if (i == n-1)
                    d[j] = triangle[i][j];
                else
                    d[j] = min(d[j], d[j+1]) + triangle[i][j];
            }
        }
        
        return d[0];
    }
};