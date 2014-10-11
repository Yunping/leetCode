/*
Problem: Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

===============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/11/2014
Difficulty: *
Review: *
Solution:...
*/
class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1, f2 = 2;
        if (n == 1) return f1;
        if (n == 2) return f2;
        
        int fn = 0;
        for (int i = 3; i <= n; ++i) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        
        return fn;
    }
};