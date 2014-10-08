/*
Problem: Palindrome Partitioning 
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
  
=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/04/2014
Difficulty: **
Review: ***^
Solution: (My own)
    1. Using DP: generate a matrix d, in which d[i][j] indicates that the sub string from i to j is palindrome.
    2. DFS: Partition s.
*/
class Solution {
public:
    
    vector<vector<string>> partition(string s) {
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
        
        vector<string> result;
        vector<vector<string> > ret;
        partition_dfs(s, n, 0, result, ret, is_palindrome);
        
        return ret;
    }
    
    void partition_dfs(string& s, int n, int start, vector<string>& result, 
                       vector<vector<string> >& ret, vector<vector<bool> >&is_palindrome) {
        if (start == n) {
            ret.push_back(result);
            return;
        }
        
        for (int end = start; end < n; ++end) {
            if (is_palindrome[start][end]) {
                result.push_back(s.substr(start, end-start+1));
                partition_dfs(s, n, end+1, result, ret, is_palindrome);
                result.pop_back();
            }
        }
    }
};