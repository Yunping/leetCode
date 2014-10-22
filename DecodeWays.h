/*
Problem: Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/20/2014
Difficulty: **^
Review: ****
Solution: DP. (第一个解法是利用DFS，但会引起TLE。看过TAG后发现可以利用DP解决)
*/
class Solution {
public:
    // DP
    int numDecodings(string s) {
        int n = s.length();
        if (!n || s[0] == '0') return 0;
        
        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] < '0' || s[i] > '9')
                return 0;
            
            if (i == 0)
                d[i] = 1;
            else {
                if (s[i-1] == '0') {
                    if (s[i] ==  '0')
                        return 0;
                    else
                        d[i] = d[i-1];
                } else {
                    int twoDigitsValue = (s[i-1]-'0') * 10 + (s[i]-'0');
                    if (twoDigitsValue <= 26 && twoDigitsValue >= 1)
                        d[i] += (i > 1 ? d[i-2] : 1);
                    if (s[i] != '0')
                        d[i] += d[i-1];
                }
            }
        }
        
        return d[n-1];
    }
    
    // DFS (TLE)
    int numDecodings_1(string s) {
        int count = 0;
        numDecodings_dfs(s, 0, count);
        return count;
    }

private:    
    void numDecodings_dfs(string &s, int i, int &count) {
        if (i >= s.length()) {
            ++count;
            return;
        }

        if (s[i] >= '1' && s[i] <= '9') {
            numDecodings_dfs(s, i+1, count);
            if (i < s.length()-1 && s[i+1] >= '0' && s[i+1] <= '9') {
                if (((s[i]-'0')*10 + (s[i+1]-'0')) <= 26) {
                    numDecodings_dfs(s, i+2, count);
                }
            }
        }
    }
};