/*
Problem: Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/10/2014
Difficulty: ****
Review: *****
Solution:
    (Not My Own)...
相关题目：
    Maximal Rectangle：https://oj.leetcode.com/problems/maximal-rectangle/
    可以用相同思想解决。矩阵每一行都可以看做一个直方图。
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        
        height.push_back(0);
        stack<int> s;
        
        int max_area = 0;
        int i = 0;
        while (i < height.size()) {
            if (s.empty() || height[s.top()] < height[i]) {
                s.push(i++);
            } else {
                int tmp = s.top();
                s.pop();
                // calculate the area between i and the next stack top. the height
                // of this area should be height[tmp] because all heights before tmp
                // should be bigger than height[tmp].
                int areaBefore = height[tmp] * (s.empty() ? i : i - s.top() - 1);
                max_area = max(max_area, areaBefore);
            }
        }
        
        return max_area;
    }
};