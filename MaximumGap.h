/*
Problem: Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

================================================================================================

Auther: Yunping, qufang83@gmail.com
Date: 07/18/2015
Difficulty: ***^
Review: ****
Solution: 
    Bucket Sort. The key is the lower bound of the gap is (max-min)/(size-1). I referred to this link:
    https://leetcode.com/discuss/27754/my-c-code-12-ms-bucket-sort-o-n-time-and-space
Tags: Sort
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;
        int min = INT_MAX, max = INT_MIN;
        for (int n : nums) {
            if (n > max) max = n;
            if (n < min) min = n;
        }
        int bucket_size = std::max(1, (max - min) / (size - 1));
        int bucket_count = (max - min) / bucket_size + 1;
        if (bucket_count <= 1) return (max - min);
        
        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);
        vector<bool> bucket_empty(bucket_count, true);
        for (int i = 0; i < size; ++i) {
            int id = (nums[i] - min) /bucket_size;
            bucket_min[id] = std::min(bucket_min[id], nums[i]);
            bucket_max[id] = std::max(bucket_max[id], nums[i]);
            bucket_empty[id] = false;
        }
        
        int max_gap = 0;
        int last_index = 0;
        for (int i = 1; i < bucket_count; ++i) {
            if (!bucket_empty[i]) {
                max_gap = std::max(bucket_min[i] - bucket_max[last_index], max_gap);
                last_index = i;
            }
        }
        
        return max_gap;
    }
};