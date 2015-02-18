/*
Problem: Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

================================================================================================

Author: Yunping, qufang83@gmail.com
Date: 02/18/2015
Difficulty: ***
Review: ***
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        
        int cur = 0;
        int max = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto it = hash.find(s[i]);
            if (it == hash.end()) {
                hash.insert(make_pair(s[i], i));
                ++cur;
            } else {
                int& last_i = hash[s[i]];
                if (last_i + cur < i)
                    ++cur;
                else
                    cur = i - last_i;
                last_i = i;
            }
            max = cur > max ? cur : max;
        }
        
        return max;
    }
};