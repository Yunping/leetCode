/*
Problem: Search for a Range
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 2015/12/27
Difficulty: ***
Review: ***
Solution: 
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int N = nums.size();
        if (N < 1) return ret;
        
        int l = 0, r = N - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target <= nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        
        // if found target, r must be the index of target's left neighbor
        if (nums[r+1] == target)
            ret[0] = r + 1;
        else
            return ret;
        
        l = 0;
        r = N - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        
        ret[1] = l - 1;
        
        return ret;
    }
};