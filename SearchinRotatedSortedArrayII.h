/*
Problem: Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 2015/12/27
Difficulty: ***
Review: ***
Solution: Only need to consider the case that a[l] == a[m] == a[r].
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 1) return -1;
        
        int l = 0, r = len - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target)
                return true;
            
            // if a[l] == a[m] == a[r], we don't know a[m] is in the first part or 
            // the second part, do the linerSearch.
            if (nums[l] == nums[r] && nums[m] == nums[l])
                return linearSearch(nums, l, r, target);
            
            if (nums[m] >= nums[l]) {
                // a[m] is in the first rotated half
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                // a[m] is in the second rotated half
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        
        return false;
    }
    
private:
    int linearSearch(const vector<int> &nums, int l, int r, int target) {
        for (int i = l; i <= r; ++i) {
            if (nums[i] == target)
                return true;
        }
        
        return false;
    }
};