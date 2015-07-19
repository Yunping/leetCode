/*
Problem: Distinct Subsequences
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/13/2014
Difficulty: ***^
Review: ****
Solution: (My Own, after see the tags)
    DP:
    d[i][j]: the number of distinct subsequences of T[0, i-1] in S[0, j-1].
    d[i][j] = d[i-1][j-1] + d[i][j-1], if T[i-1] equals S[j-1], else,
    d[i][j] = d[i][j-1]
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = T.size();
        int n = S.size();
        
        vector<vector<int> > d(m+1, vector<int>(n+1, 0));
        
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0)
                    d[i][j] = 1;
                else if (j == 0)
                    d[i][j] = 0;
                else {
                    if (T[i-1] == S[j-1])
                        d[i][j] = d[i-1][j-1] + d[i][j-1];
                    else
                        d[i][j] = d[i][j-1];
                }
            }
        }
        
        return d[m][n];
    }
};