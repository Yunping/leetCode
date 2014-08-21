/*
Problem: Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

===================================================================

Author: Yunping
Date: 08/21/2014
Difficulty: **^
Review: ***
Solution: backtracking
*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        buildUsedMap(board);
        doSolve(board, 0, 0);
    }

private:
    const static int N = 9;
    short row_used[N];
    short col_used[N];
    short cell_used[N];
    
    void buildUsedMap(vector<vector<char> > &board) {
        row_used[N] = { 0 };
        col_used[N] = { 0 };
        cell_used[N] = { 0 };
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != '.') {
                    short mask = (1 << (board[i][j] - '1'));
                    row_used[i] |= mask;
                    col_used[j] |= mask;
                    cell_used[(i / 3) * 3 + j / 3] |= mask;
                }
            }
        }
    }
    
    bool doSolve(vector<vector<char> > &board, int row, int col) {
        if (row >= N) return true;
        
        int next_row = col == N-1 ? row + 1 : row;
        int next_col = col == N-1 ? 0 : col + 1;
        
        if (board[row][col] == '.') {
            for (char x = '1'; x <= '9'; ++x) {
                if (mark(board, row, col, x)) {
                    if (doSolve(board, next_row, next_col))
                        return true;
                    
                    unmark(board, row, col, x);
                }
            }
            
            return false;
            
        } else {
            return doSolve(board, next_row, next_col);
        }
    }
    
    bool mark(vector<vector<char> > &board, int row, int col, char x) {
        short mask = (1<<(x - '1'));
        if (!(row_used[row] & mask) && !(col_used[col] & mask) && 
            !(cell_used[(row/3)*3 + col/3] & mask)) {
            row_used[row] |= mask;
            col_used[col] |= mask;
            cell_used[(row / 3) * 3 + col / 3] |= mask;
            board[row][col] = x;
            return true;
        }
        return false;
    }
    
    void unmark(vector<vector<char> > &board, int row, int col, char x) {
        short mask = (1<<(x - '1'));
        row_used[row] &= ~mask;
        col_used[col] &= ~mask;
        cell_used[(row / 3) * 3 + col / 3] &= ~mask;
        board[row][col] = '.';
    }
};