/*
Problem: Remove Element

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: Aug 1, 2014
Update: 11/212015
Difficulty: *^
Review: *^
Solution:
1. two pointers
2. partition
3. two pointers and swap to-delete elements to the end

*/
class Solution {
public:
    // solution 1: two pointers
    int removeElement1(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int i = 0, j = 0;
        int len = nums.size();
        while (j < len) {
            if (nums[j] != val)
                nums[i++] = nums[j];
            ++j;
        }
        
        return i;
    }
    
    // solution 2: partition
    int removeElement2(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int i = -1, j = 0;
        int len = nums.size();
        while (j < len) {
            if (nums[j] == val)
                ++j;
            else
                swap(nums[++i], nums[j++]);
        }
        return i+1;
    }
    
    // solution 3:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int len = nums.size();
        int i = 0, j = len - 1;
        while (i <= j) {
            while (i <= j && nums[i] != val)
                ++i;
            while (i <= j && nums[j] == val)
                --j;
            if (i < j)
                swap(nums[i++], nums[j--]);
        }
        
        return (j + 1);
    }
    
private:
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
};