/*
Problem: Implement strStr()
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

Author: Yunping, qufang83@gmail.com
Date: 08/03/2014
Difficulty: **
Review: ***
Note: An easy one. But made a mistake at the first time...
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char *h = haystack;
        char *n = needle;
        if (!h || !n) return 0;
        
        char *ret = h;
        while (*h != '\0' && *n != '\0') {
            if (*h == *n) {
                ++h;
                ++n;
            } else {
                h = ++ret;
                n = needle;
            }
        }
        
        return *n == '\0' ? ret : 0;
    }
};