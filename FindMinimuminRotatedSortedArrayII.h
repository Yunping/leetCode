/*
Problem: Find Minimum in Rotated Sorted Array II
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/28/2014
Difficulty: ***
Review: ****
Solution: (My Own)
    Binary Search
    - if num[m] == num[l] == num[r], we have to use linear search. else,
    - if num[l] < num[r], the array isn't rotated, so return num[l]. else,
    - if in this case, we must have num[l] >= num[r]:
        a. if num[m] >= num[l], the min value should be in the right part, or
        b. else, the min value should be in the left part including num[m].
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int l = 0, r = n-1;
        
        while (l < r) {
            if (l == r || num[l] < num[r])
                break;
                
            int m = (l + r)>>1;
            if (num[l] == num[r] && num[l] == num[m])
                return findMinLinear(num, l, r);
            
            // a[l] >= a[r]
            if (num[m] >= num[l])
                l = m + 1;
            else
                r = m;
        }
        
        return num[l];
    }
    
private:
    int findMinLinear(vector<int> &num, int l, int r) {
        int min = INT_MAX;
        for (int i = l; i <= r; ++i) {
            if (num[i] < min)
                min = num[i];
        }
        
        return min;
    }
};