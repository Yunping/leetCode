/*
Author: Yunping
Date: 07/03/2014
Difficulty: *

Problem: Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

Solution: 
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size();
        string ret;
        int firstLen = len > 0 ? strs[0].length() : 0;
        for (int i = 0; i < firstLen; ++i) {
            for (int j = 1; j < len; ++j) {
                if (i >= strs[j].length() || strs[0][i] != strs[j][i])
                    return ret;
            }
            ret.push_back(strs[0][i]);
        }
        
        return ret;
    }
};