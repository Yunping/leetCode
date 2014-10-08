/*
Problem: Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: **
Review: ***^
Solution: (My Own) O(n), O(1)
    the max profit if buy stock on day i: profit[i] = max(prices[j]) - prices[i]. (i <= j < n)
    so from i from n-1 to 0, calculate each profit[i] and get the maximum profit.
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        
        int n = prices.size();
        int maxProfit = 0;
        int maxSell = prices[n-1];
        
        for (int i = n-2; i >= 0; --i) {
            int profit = maxSell - prices[i];
            if (profit > maxProfit)
                maxProfit = profit;
            if (prices[i] > maxSell)
                maxSell = prices[i];
        }
        
        return maxProfit;
    }
};