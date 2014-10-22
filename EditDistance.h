/*
Problem: Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/21/2014
Difficulty: ***^
Review: *****
Solution: 
    1. (My Own) Recursion (TLE)
    2. DP: 令d(i, j)为word1(0~i)和word2(0~j)的最小距离，则
        d(i, j) = d(i-1, j-1), when word1[i] == word2[j], or
        d(i, j) = min(d(i-1, j), d(i, j-1), d(i-1, j-1)) + 1
        第二项三个d分别对应于
            删除word1[i]/或在word2[j]后insert word1[i])
            删除word2[j]/或在word1[i]后insert word2[j])
            修改word1[i]或word2[j]使之相等
        
    *NOTE* 看了提示后想到可以利用DP解决。很多递归问题都可以转化为动态规划。
*/
class Solution {
public:
    // DP
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (!m) return n;
        if (!n) return m;
        
        vector<vector<int> > d(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (word1[i] == word2[j]) {
                    if (!i && !j)
                        d[i][j] = 0;
                    else if (!i)
                        d[i][j] = j;
                    else if (!j)
                        d[i][j] = i;
                    else
                        d[i][j] = d[i-1][j-1];
                } else {
                    if (!i && !j)
                        d[i][j] = 1;
                    else if (!i)
                        d[i][j] = d[i][j-1] + 1;
                    else if (!j)
                        d[i][j] = d[i-1][j] + 1;
                    else
                        d[i][j] = min(min(d[i][j-1], d[i-1][j]), d[i-1][j-1]) + 1;
                }
            }
        }
        
        return d[m-1][n-1];
    }
    
    // Recursion (TLE)
    int minDistance_recursive(string word1, string word2) {
        if (word1.empty())
            return word2.length();
        if (word2.empty())
            return word1.length();
            
        if (word1[0] == word2[0]) {
            return minDistance(word1.substr(1), word2.substr(1));
        } else {
            int t1 = 1 + minDistance(word1.substr(1), word2.substr(1));
            int t2 = 1 + minDistance(word1, word2.substr(1));
            int t3 = 1 + minDistance(word1.substr(1), word2);
            return min(t1, min(t2, t3));
        }
    }
};