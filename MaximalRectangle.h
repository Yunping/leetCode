/*
Problem: Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

=====================================================================================

Author: Yunping,
Date: 10/10/2014
Difficulty: ****
Review: ****
Solution:
    参看相关题目的题解，本题可以由之转化而来。

相关题目：
Largest Rectangle in Histogram：
https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int max_area = 0;
        vector<int> h(n+1, 0);
        h[n] = 0;
        for (int i = 0; i < m; ++i) {
            matrix[i].push_back('0');
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    h[j]++;
                } else {
                    h[j] = 0;
                }
            }

            stack<int> s;
            for (int j = 0; j <= n; ) {
                if (s.empty() || h[j] > h[s.top()])
                    s.push(j++);
                else {
                    int tmp = s.top();
                    s.pop();
                    max_area = max(max_area, h[tmp] * (s.empty()? j : j-s.top()-1));
                }
            }
        }
        
        return max_area;
    }
};