/*
Problem: Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

==========================================================================================

Author: Yunping,
Date: 12/13/2015
Difficulty: ***
Review: ***^
Solution: See the comments. (from JJ. Hou's Stl Code Internals)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return;
        
        // step 1: from back to forth, find the first pairs that make nums[i] < nums[i+1]. 
        int i = len - 2, ii = len - 1;
        while (i >= 0) {
            if (nums[i] < nums[ii])
                break;
            --i;
            --ii;
        }
        
        // step 2: from back to forth until nums[i], find the first element which is bigger than nums[i].
        if (i >= 0) {
            for (int k = len - 1; k >= ii; --k) {
                 if (nums[k] > nums[i]) {
                     swap(nums[i], nums[k]);
                     break;
                 }
            }
        }
        
        // step 3: revert nums[ii] to the end.
        reverse(nums.begin() + ii, nums.end());
    }
};