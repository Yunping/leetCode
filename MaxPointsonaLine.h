/*
Problem: Max Points on a Line
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

==============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/12/2014
Difficulty: ***
Review: ****
Solution:
    For each point from i to n-1, count the number of points whose slopes with points[i] are the same.
    get the maximum count with the same slope.
    
    *NOTE* consider the duplicates
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    
    double getSlope(Point& p1, Point& p2) {
        if (p1.x == p2.x)
            return std::numeric_limits<double>::infinity();
        
        return ((double)(p1.y - p2.y) / (double)(p1.x - p2.x));
    }
    
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int max_count = 0;
        
        // map the count of points with the same slope between them and point[i].
        unordered_map<double, int> slope_i;
        for (int i = 0; i < n-1; ++i) {
            int dups_i = 0; // dups points number with point[i]
            int max_same_scope_count = 1;   // max points number with the same slope. the initial value is 1 for point[i]
            for (int j = i+1; j < n; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    ++dups_i;
                else {
                    double k = getSlope(points[i], points[j]);
                    if (slope_i.find(k) != slope_i.end())
                        ++slope_i[k];
                    else
                        slope_i[k] = 2;
                    
                    max_same_scope_count = max(max_same_scope_count, slope_i[k]);
                }
            }
            
            max_count = max(max_count, max_same_scope_count + dups_i);
            
            // clear the hash map for the next loop. 
            slope_i.clear();
        }
        
        return max_count;
    }
};