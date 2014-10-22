/*
Problem: Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/15/2014
Difficulty: ***
Review: ***
Solution:
    (My Own) Time: O(mn), Space: O(m+n)
*/
class Solution {
public:
    // space o(m+n)
    void setZeroes_1(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!matrix[i][j]) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rows[i] || cols[j])
                    matrix[i][j] = 0;
            }
        }
    }
    
    // space o(1)
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // check the first row
        bool first_row_zero = false;
        for (int i = 0; i < n; ++i) {
            if (!matrix[0][i]) {
                first_row_zero = true;
                break;
            }
        }
        
        // check the first col
        bool first_col_zero = false;
        for (int i = 0; i < m; ++i) {
            if (!matrix[i][0]) {
                first_col_zero = true;
                break;
            }
        }
        
        // check other rows and cols, store the result into
        // the first row/col
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        // set zero according to the fist row/col
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // set zero for this first row/col
        if (first_row_zero)
            for (int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        if (first_col_zero)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};