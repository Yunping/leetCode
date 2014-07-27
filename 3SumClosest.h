/*
Problem: 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    
Date: 07/27/2014
Difficulty: **^
Review: **^
Note: Similiar with "3Sum" problem. Keep an eye if:
if 2*num[l]>cur2Sum+absMin, or 2*num[r]+absMin < cur2Sum
*/
    
class Solution {
public:
    int absDiff(int a, int b) {
        if (a > b)
            return (a - b);
        else
            return (b - a);
    }
    
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int len = num.size();
        if (len < 3) return 0;
        
        int absMin = INT_MAX;
        int closest = num[0] + num[1] + num[2];
        
        for (int i = 0; i < len - 2; ++i) {
            int cur2Sum = target - num[i];
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                int sum2 = num[l] + num[r];
                if (sum2 == cur2Sum)
                    return target;
                    
                // The possible range of 2sum is 2*num[l] ~ 2*num[r], if 2*num[l]>cur2Sum+absMin,
                // or 2*num[r]+absMin < cur2Sum, we can terminate the loop here.
                if (2 * num[l] - cur2Sum > absMin || cur2Sum - 2 * num[r] > absMin)
                    break;
                    
                if (absDiff(target, sum2 + num[i]) < absMin) {
                    absMin = absDiff(target, sum2 + num[i]);
                    closest = sum2 + num[i];
                }
                
                if (sum2 < cur2Sum)
                    ++l;
                else if (sum2 > cur2Sum)
                    --r;
            }
        }
        
        return closest;
    }
};