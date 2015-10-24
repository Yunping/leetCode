/*
Problem: 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

===========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 07/27/2014
Refactor: 10/24/2015
Difficulty: **
Review: *^
Solution: Similiar with 3Sum.
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 3) return 0;
        sort(nums.begin(), nums.end());
        
        int min_delta = INT_MAX;
        for (int i = 0; i < len - 2; ++i) {
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                int two_sum = nums[l] + nums[r];
                int delta = two_sum - (target - nums[i]);
                if (delta == 0) {
                    return target;
                } else if (delta > 0)
                    --r;
                else
                    ++l;
                if (abs(delta) < abs(min_delta)) {
                    min_delta = delta;
                }
            }
        }
        
        return (target + min_delta);
    }
};