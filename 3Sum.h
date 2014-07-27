/*
Author: Yunping
Date: 07/03/2014
Difficulty: **

Problem: 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
    
Solution:
3Sum -> 2Sum
Keys:
-Avoid Dups
-Avoid unnecessary calcs
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        int len = num.size();
        if (len <= 2) return ret;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < len - 2 && num[i] <= 0; ++i) { // num[i] must not bigger than zero.
            // avoid dups
            if (i > 0 && num[i] == num[i-1])
                continue;
            int sum = 0 - num[i];
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                int s = num[l] + num[r];
                if (s == sum) {
                    vector<int> result;
                    result.push_back(num[i]);
                    result.push_back(num[l]);
                    result.push_back(num[r]);
                    ret.push_back(result);
                    
                    // avoid dups
                    while (l < r && num[l] == result[1])
                        ++l;
                    while (l < r && num[r] == result[2])
                        --r;
                } else if (s > sum)
                    --r;
                else
                    ++l;
            }
        }

        return ret;
    }
};