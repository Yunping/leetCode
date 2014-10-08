/*
Problem: Jump Game II
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/03/2014
Difficulty: ***
Review: ****
Solution: 贪心法 (My own but didn't feel that easy...)
    1. for each position before current reachable position, calculate the farthest 
       position can be reached by 1 jump.
    2. once the farthest position is equals or farther then the last position, return steps.
    3. if not, update the reachable position and steps, set current position as the previous 
        farthest reachable position (no need to calculate the position before it because the 
        farthest position they can reach must not be greater.), then go to step1.
*/

class Solution {
public:
    int jump(int A[], int n) {
        if (!A || n <= 1) return 0;
        
        int reach = 1;
        int step = 1;
        int next_begin = 0;
        while (true) {
            int next_reach = reach; // next farthest reachable position by one jump.
            for (int i = next_begin; i < reach; ++i) {
                next_reach = max(next_reach, A[i] + i + 1);
                if (next_reach >= n)
                    return step;
            }
            
            if (next_reach == reach) {
                // unreachable...
                return -1;
            }
            
            next_begin = reach;
            reach = next_reach;
            ++step;
        }
        
        return step;
    }
    
    // DP... but not good enough. time exceeded.
    int jump_time_exceeded(int A[], int n) {
        if (!A || n <= 0) return 0;
        
        vector<int> min_jump(n, INT_MAX);
        vector<bool> valid(n, true);
        min_jump[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (!valid[j])
                    continue;
                if (j+A[j] >= i) {
                    if (min_jump[j]+1 < min_jump[i])
                        min_jump[i] = min_jump[j] + 1;
                } else
                    valid[j] = false;
            }
        }
        
        return min_jump[n-1];
    }
};