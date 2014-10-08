/*
Problem: Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

=====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/02/2014
Difficulty: **
Review: ***
Solution:
- For intervals before the new one, add it to the result.
- For intervals have overlap with new one, merge them into the new one.
- For intervals behind the new one, add it to the result.
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
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        
        bool inserted = false;
        for (auto v:intervals) {
            if (v.end < newInterval.start) {
                // v is before newInterval and has no overlap with newInterval
                ret.push_back(v);
            } else if (v.start > newInterval.end) {
                // v is behind newInterval. Insert newInterval if havn't. Insert v.
                if (!inserted) {
                    // find the insert pos
                    ret.push_back(newInterval);
                    inserted = true;
                }
                ret.push_back(v);
            }
            else {
                // v has overlap with newInterval, merge them into newInterval
                newInterval.start = min(newInterval.start, v.start);
                newInterval.end = max(newInterval.end, v.end);
            }
        }
        
        if (!inserted)
            ret.push_back(newInterval);
            
        return ret;
    }
};