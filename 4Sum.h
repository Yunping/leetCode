/*
Problem: 4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    
====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/24/2015
Difficulty: *^
Review: *^
Solution:
    4sum -> 3sum -> 2sum
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int len = nums.size();
        if (len < 4) return ret;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; ++i) {
            // avoid dups
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int target3 = target - nums[i];
            for (int j = i + 1; j < len - 2; ++j) {
                // avoid dups
                if (j > i+1 && nums[j-1] == nums[j]) continue;
                int target2 = target3 - nums[j];
                int l = j + 1, r = len - 1;
                while (l < r) {
                    int sum2 = nums[l] + nums[r];
                    if (sum2 == target2) {
                        int a[] = { nums[i], nums[j], nums[l], nums[r] };
                        ret.push_back(vector<int>(a, a + 4));
                        // avoid dups
                        while (nums[l] == a[2]) ++l;
                        while (nums[r] == a[3]) --r;
                    } else if (sum2 > target2)
                        --r;
                    else
                        ++l;
                }
            }
        }
        
        return ret;
    }
};