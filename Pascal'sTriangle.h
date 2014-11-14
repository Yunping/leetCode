/*
Problem: Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/12/2014
Difficulty: *^
Review: **
Solution: (My Own)
    Construct level by level
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > rows;
        if (numRows <= 0) return rows;
        
        for (int r = 0; r < numRows; ++r) {
            vector<int> row(r+1, 1);
            for (int i = 1; i <= r; ++i) {
                if (i == r)
                    row[i] = rows[r-1][i-1];
                else
                    row[i] = rows[r-1][i-1] + rows[r-1][i];
            }
            
            rows.push_back(row);
        }
        
        return rows;
    }
};