/*
Problem: Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/17/2015
Difficulty: *
Review: *
Solution:
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        int count = strs.size();
        if (!strs.empty()) {
            int length = strs[0].length();
            for (int i = 0; i < length; ++i) {
                char c = strs[0][i];
                for (int j = 1; j < count; ++j) {
                    if (i >= strs[j].length() || strs[j][i] != c)
                        return ret;
                }
                ret.push_back(c);
            }
        }
        
        return ret;
    }
};