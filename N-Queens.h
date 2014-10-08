/*
Problem:
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Author: Yunping, qufang83@gmail.com
Date: 09/29/2014
Difficulty: *^
Review: ***
Note: back-tracking...
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        if (n <= 0) return ret;
        
        int *rows = new int[n];
        doSolveNQueens(rows, n, 0, ret);
        
        delete []rows;
        
        return ret;
    }
    
    void doSolveNQueens(int *rows, int n, int index, vector<vector<string> >& ret) {
        if (index == n) {
            vector<string> result;
            for (int i = 0; i < n; ++i) {
                string line;
                for (int j = 0; j < n; ++j) {
                    if (rows[i] == j)
                        line.push_back('Q');
                    else
                        line.push_back('.');
                }
                result.push_back(line);
            }
            
            ret.push_back(result);
            
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            rows[index] = i;
            if (check(rows, index))
                doSolveNQueens(rows, n, index+1, ret);
        }
    }
    
    bool check(int *rows, int index) {
        for (int i = 0; i < index; ++i) {
            if (rows[i] == rows[index])
                return false;
            if (i + rows[i] == rows[index] + index)
                return false;
            if (i - rows[i] == index - rows[index])
                return false;
        }
        
        return true;
    }
};