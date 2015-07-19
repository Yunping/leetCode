/*
Problem: Find Peak Element
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.
Note:

Your solution should be in logarithmic complexity.

==============================================================================

Author: Yunping, qufang83@gmail.com
Date: 01/25/2015
Difficulty: **
Review: ***^
Solution: (After see the tags)
    - Binary Search
*/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int len = num.size();
        return findPeakElement(num, 0, len-1);
    }
    
private:
    int findPeakElement(const vector<int> &num, int left, int right) {
        if (left > right) return -1;
        if (left == right) return left;
        if (right - left == 1) return num[left] > num[right] ? left : right;
        
        int mid = left + (right - left) / 2;
        int lt = mid - 1;
        int rt = mid + 1;
        if (num[mid] > num[lt] && num[mid] > num[rt])
            return mid;
        else if (num[rt] > num[lt])
            return findPeakElement(num, rt, right);
        else
            return findPeakElement(num, left, lt);
    }
};