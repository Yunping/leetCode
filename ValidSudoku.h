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
Solution: Only one pass traverse.
1. Use a row map, a col map, and 3 cell maps, to record the number that has been used.
2. Traverse by rows/cols, check each elem in every row/col/cell. Reset the map for 
   rows/cols every row/col. Reset the cell maps every 3 rows.
3. Use bit manipulation. Space: sizeof(short)*2 + sizeof(int)
*/
   
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int N = 9;
        short row_used = 0, col_used = 0;
        int cell_used = 0;
        for (int i = 0; i < N; ++i) {
            row_used = col_used = 0;
            if (i % 3 == 0)
                cell_used = 0;
            
            for (int j = 0; j < N; ++j) {
                char row_elem = board[i][j];
                if (row_elem != '.') {
                    int row_idx = row_elem - '1';
                    // check rows
                    if (row_used & (1<<row_idx))
                        return false;
                    row_used |= (1<<row_idx);
                    
                    // check cells
                    if (cell_used & (1<<(N*(j/3) + row_idx)))
                        return false;
                    cell_used |= (1<<(N*(j/3) + row_idx));
                }
                
                // check cols
                char col_elem = board[j][i];
                if (col_elem != '.') {
                    int col_idx = col_elem - '1';
                    if (col_used & (1<<col_idx))
                        return false;
                    col_used |= (1<<col_idx);
                }
            }
        }
        
        return true;
    }
};