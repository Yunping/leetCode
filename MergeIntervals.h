/*
Problem: Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Author: Yunping, qufang83@gmail.com
Date: 10/02/2014
Difficulty: **
Review: ****
Solution: 
1. sort intervals by 'start'. O(N*logN)
2. merge them from the pairs by pairs. O(N)

*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    struct IntervalCmp {
        bool operator()(Interval v1, Interval v2) {
            return (v1.start < v2.start);
        }
    };
    
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        size_t n = intervals.size();
        if (!n) return ret;
        
        sort(intervals.begin(), intervals.end(), IntervalCmp());
        
        for(int i = 1; i < n; ++i) {
            Interval &vi = intervals[i];
            Interval &vii = intervals[i-1];
            if (vi.start <= vii.end) {
                // merge vi and vii: vi = vi + vii, discard vii.
                vi.start = vii.start;
                vi.end = max(vi.end, vii.end);
            } else
                ret.push_back(vii); // add vii as result.
        }
        
        // add the last interval.
        ret.push_back(intervals[n-1]);
        
        return ret;
    }
};