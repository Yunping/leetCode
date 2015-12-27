/*
Problem: Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

====================================================================================================

Author: Yunping, qufang83@gmail.com
Date: 2015/12/27
Difficulty: **^
Review: **^
Solution:
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size();
        int l = 0, r = N - 1;
        while (l <=r) {
            int m = (l + r) >> 1;
            if (target == nums[m])
                return m;
            if (target > nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        
        // l will always be the position to insert after the loop ends
        return l;
    }
};