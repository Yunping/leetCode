/*
Problem: Candy
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

======================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/21/2014
Difficulty: **
Review: ***
Solution: (My Own)...
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> candys(n, 1);
        
        int candyNum = n;
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i-1]) {
                int old = candys[i];
                candys[i] = candys[i-1] + 1;
                candyNum += (candys[i] - old);
            }
        
        for (int i = n-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1] && candys[i] <= candys[i+1]) {
                int old = candys[i];
                candys[i] = candys[i+1] + 1;
                candyNum += (candys[i] - old);
            }
            
        return candyNum;
    }
};