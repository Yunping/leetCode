/*
Problem: Interleaving String
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/14/2014
Difficulty: ****
Review: ****
Solution:
    DP (My Own, after see the "tags")
    d[i, j] indicates that s3(0, i+j-1) is formed by s1(0, i-1) and s2(0, j-1), then
    d[i, j] = d[i-1, j] && s1[i-1] == s3[i+j-1] || d[i, j-1] && s2[j-1] == s3[i+j-1]
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();
        
        if (k != m + n) return false;
        vector<vector<bool> > d(m+1, vector<bool>(n+1, false));
        d[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (s3[i-1] == s1[i-1])
                d[i][0] = true;
            else
                break;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (s3[i-1] == s2[i-1])
                d[0][i] = true;
            else
                break;
        }
        
        for (int len = 2; len <= k; ++len) {
            for (int i = 1; i <= min(m, len-1); ++i) {
                int j = len - i;
                if (j > n) continue;
                if (d[i-1][j] && s1[i-1] == s3[len-1])
                    d[i][j] = true;
                else if (d[i][j-1] && s2[j-1] == s3[len-1])
                    d[i][j] = true;
            }
        }
        
        return d[m][n];
    }
};