/*
Problem: Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/12/2014
Difficulty: ***
Review: ****
Solution:
    My own solution is not good enough.
*/
class Solution {
public:
    // Other's solution. No need to calc the maximum continuous sum
    // just find the point.
    int canCompleteCircuit_1(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int left = 0;
        int delta = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            left += gas[i] - cost[i];
            delta += gas[i] - cost[i];
            if (delta < 0) {
                delta = 0;
                start = i + 1;
            }
        }
        
        if (left < 0) return -1;
        return start % n;
    }
    
    // My Solution. Calc the maximum continuous sum of array delta.
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        vector<int> delta(n, 0);
        int left = 0;
        for (int i = 0; i < n; ++i) {
            delta[i] = gas[i] - cost[i];
            left += delta[i];
        }
        
        if (left < 0) return -1;
        
        int cur = 0;
        int max = INT_MIN;
        int from = 0;
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (cur < 0) {
                cur = delta[i%n];
                f = i%n;
            } else
                cur += delta[i%n];
                
            if (cur > max) {
                from = f;
                max = cur;
            }
        }
        
        return from;
    }
};