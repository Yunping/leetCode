/*
Problem: Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/13/2014
Difficulty: **
Review: **^
Solution: (My Own)
    copy from back to forth
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 1);
        
        for (int r = 1; r <= rowIndex; ++r) {
            int prev = 1;
            for (int i = r-1; i > 0; --i)
                row[i] += row[i-1];
        }
        
        return row;
    }
};