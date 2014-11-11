/*
Problem: Word Break
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/11/2014
Difficulty: ***
Review: ****
Solution: 
    Method1: DP
        d[i] represents whether s[0~i-1] can be segmented.
        d[i] = d[j] && (s[j~i] exist in dict)
    Method2: DFS. (TLE)
*/
class Solution {
public:
    // DP: Refer to others.
    // d[i] represents whether s[0~i-1] can be segmented.
    // d[i] = d[j] && (s[j~i] exist in dict)
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> d(n+1, false);
        d[0] = true;
        
        // for each length l from 1,to n, calc d[l]
        for (int l = 1; l <= n; ++l) {
            for (int j = 0; j < l; ++j) {
                if (d[j] && dict.find(s.substr(j, l-j)) != dict.end()) {
                    d[l] = true;
                    break;
                }
            }
        }
        
        return d[n];
    }
    
    // DFS: TLE
    bool wordBreak_dfs(string s, unordered_set<string> &dict) {
        if (s.empty()) return true;
        
        return wordBreak_dfs(s.c_str(), s.size(), dict);
    }
    
private:
    bool wordBreak_dfs(const char *s, int n, unordered_set<string> &dict) {
        if (n <= 0) return true;
        
        for (int l = 1; l < n; ++l) {
            if (dict.find(string(s, s+l)) != dict.end()) {
                if (wordBreak_dfs(s+l, n-l, dict))
                    return true;
            }
        }
        
        return false;
    }
};