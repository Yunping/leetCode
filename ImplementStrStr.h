/*
Problem: Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/21/2015
Difficulty: *
Review: *^
Solution:

*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() && needle.empty()) return 0;
        int len1 = haystack.length();
        int len2 = needle.length();
        if (len2 > len1) return -1;
        
        for (int i = 0; i <= len1 - len2; ++i) {
            int j = 0;
            for (; j < len2; ++j) {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j == len2)
                return i;
        }
        
        return -1;
    }
};