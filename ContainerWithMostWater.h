/*
Problem: Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/11/2015
Difficulty: **
Review: **^
Solution: two pointers
*/
class Solution {
private:
    int min(int a, int b) {
        return a > b ? b : a;
    }
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0;
        int max_area = INT_MIN;
        int i = 0, j = len - 1;
        while (i < j) {
            int cur_height = min(height[i], height[j]);
            int cur_area = (j - i) * cur_height;
            while (height[i] <= cur_height && i < j)
                ++i;
            while (height[j] <= cur_height && i < j)
                --j;
            max_area = max(max_area, cur_area);
        }
        
        return max_area;
    }
};