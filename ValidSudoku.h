/*
Problem: Valid Sudoku
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

==============================================================================

Author: Yunping, qufang83@gmail.com
Date: 08/20/2014
Difficulty: *^
Review: **^
Solution: o(n^2), one pass traverse.
1. Use a row map, a col map, and 3 cell maps, to record the number that has been used.
2. Traverse by rows/cols, check each elem in every row/col/cell. Reset the map for 
   rows/cols every row/col. Reset the cell maps every 3 rows.
*/
   
class Solution {
public:
    // My own solution
    bool isValidSudoku(vector<vector<char> > &board) {
        // first check rows
        bool row_used[9];
        bool col_used[9];
        bool cell_used[3][9];
        
        for (int i = 0; i < 9; ++i) {
            memset(row_used, false, 9);
            memset(col_used, false, 9);
            if (i % 3 == 0) {
                memset(cell_used[0], false, 9);
                memset(cell_used[1], false, 9);
                memset(cell_used[2], false, 9);
            }
            for (int j = 0; j < 9; ++j) {
                // check rows
                char row_elem = board[i][j];
                if (row_elem >= '1' && row_elem <= '9') {
                    if (row_used[row_elem - '1'])
                        return false;
                    row_used[row_elem - '1'] = true;
                } else if (row_elem != '.')
                    return false;
                    
                // check cols
                char col_elem = board[j][i];
                if (col_elem >= '1' && col_elem <= '9') {
                    if (col_used[col_elem - '1'])
                        return false;
                    col_used[col_elem - '1'] = true;
                } else if (col_elem != '.')
                    return false;
                    
                // check cells
                char cell_elem = board[i][j];
                if (cell_elem >= '1' && cell_elem <= '9') {
                    if (cell_used[j/3][cell_elem - '1'])
                        return false;
                    cell_used[j/3][cell_elem - '1'] = true;
                } else if (cell_elem != '.')
                    return false;
            }
        }
        
        return true;
    }
};