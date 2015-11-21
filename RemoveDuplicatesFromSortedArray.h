/*
Problem: Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: Aug 1, 2014
Update: 11/21/2015
Difficulty: *
Review: *^
Solution: two-pointers
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0, j = i + 1;
        int len = nums.size();
        while (j < len) {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
            ++j;
        }
        return (i+1);
    }
};