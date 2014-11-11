/*
Problem: Find Minimum in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/27/2014
Difficulty: **^
Review: ***
Solution: (My Own)
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int l = 0, r = n-1;
        while (l <= r) {
            if (l == r || num[l] < num[r])
                break;
            int m = (l+r)>>1;
            if (num[m] >= num[l])
                l = m + 1;
            else
                r = m;
        }
        
        return num[l];
    }
};