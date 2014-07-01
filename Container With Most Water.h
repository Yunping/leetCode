/*
Problem: Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Source: https://oj.leetcode.com/problems/container-with-most-water/
Date: 07/01/2014
Difficulty: **
Note: 此题不难，但是采用的方法比较巧妙，而不是直观的暴利法

*/
class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0;
        while (i < j) {
            int cur_height = min(height[i], height[j]);
            int area = cur_height * (j-i);
            if (area > max) max = area;
            
            while (height[i] <= cur_height && i < j)
                ++i;
            while (height[j] <= cur_height && j > i)
                --j;
        }
        
        return max;
    }
};