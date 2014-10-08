/*
Problem: Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

====================================================================================

Author: Yunping,
Date: 10/07/2014
Difficulty: **^
Review: ****
Solution: DP.
    f(i) means the max profit if one trasaction happend during day(0) ~ day(i).
    g(i) means the max profit if one trasaction happend during day(i) ~ day(n-1).
    determin an 'i' which makes maximum f(i) + g(i)
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        
        // f(i) means the max profit if one trasaction happend during day(0) ~ day(i).
        vector<int> f(n, 0);
        int min_buy = INT_MAX;
        int max_f = INT_MIN;
        for (int i = 0; i < n; ++i) {
            min_buy = min(min_buy, prices[i]);
            max_f = max(max_f, prices[i] - min_buy);
            f[i] = max_f;
        }
        
        // g(i) means the max profit if one trasaction happend during day(i) ~ day(n-1).
        vector<int> g(n, 0);
        int max_sell = INT_MIN;
        int max_g = INT_MIN;
        for (int i = n-1; i >= 0; --i) {
            max_sell = max(prices[i], max_sell);
            max_g = max(max_g, max_sell - prices[i]);
            g[i] = max_g;
        }
        
        // determin an 'i' which makes maximum f(i) + g(i)
        int max_profit = 0;
        for (int i = 0; i < n; ++i)
            max_profit = max(max_profit, f[i]+g[i]);
            
        return max_profit;
    }
};