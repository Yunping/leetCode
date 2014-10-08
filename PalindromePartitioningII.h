/*
Problem: Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/04/2014
Difficulty: ****
Review: ****
Solution:
    (参考了别人的解法。DP的关键在于找出合适的状态方程)
    1. First, in order to check if substr[i, j] is palindrome, pre-processing s using DP
    2. Second, using another DP: d[i] is the min cut needed for substr[i, n-1].
       d[i] = (min{d[j+1] + 1}, i<=j<n-1) or (d[i] = 0, j=n-1) when substr[i, j] is palindrome.
    3. d[0] is the result.
*/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // pre-processing using DP, in order to check palindrome quickly. 
        vector<vector<bool> > is_palindrome(n, vector<bool>(n, true));
        for (int d = 0; d < n; ++d) {
            for (int i = 0, j = d; i < n-d; ++i, ++j) {
                if (i == j)
                    is_palindrome[i][j] = true;
                else if (j-i == 1)
                    is_palindrome[i][j] = (s[i] == s[j]);
                else
                    is_palindrome[i][j] = (is_palindrome[i+1][j-1] && s[i] == s[j]);
            }
        }
        
        // DP: d[i] is the min cut needed for substr[i, n-1].
        // d[i] = (min{d[j+1] + 1}, i<=j<n-1) or (d[i] = 0, j=n-1) when substr[i, j] is palindrome.
        vector<int> d(n, n-1);
        for (int i = n-1; i >= 0; --i) {
            for (int j = n-1; j >= i; --j) {
                if (is_palindrome[i][j]) {
                    if (j == n-1) {
                        d[i] = 0;
                        break;
                    } else if(d[j+1] + 1 < d[i])
                        d[i] = d[j+1] + 1;
                }
            }
        }
        
        return d[0];
    }
};