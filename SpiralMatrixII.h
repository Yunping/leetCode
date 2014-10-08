/*
Problem: Spiral Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/04/2014
Difficulty: *
Review: **
Solution: (My own) generate by circle...
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > mtrx(n, vector<int>(n, 1));
        
        int circles = (n + 1) >> 1;
        int value = 1;
        for (int i = 0; i < circles; ++i) {
            int x = i, y = i;
            // top: left->right. y:[i -> n-i-1]
            for (; y < n-i; ++y)
                mtrx[x][y] = value++;
                
            // right: up->down. x:(i, n-i-1]
            for (--y, ++x; x < n-i; ++x)
                mtrx[x][y] = value++;
            
            // bottom: right->left. y:(n-i-1, i]
            if (--x > i) {
                for (--y; y >= i; --y)
                    mtrx[x][y] = value++;
            }
            
            // left: down->up. x:(n-i-1, i)
            if (++y < n-i-1) {
                for (--x; x > i; --x)
                    mtrx[x][y] = value++;
            }
        }
        
        return mtrx;
    }
};