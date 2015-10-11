/*
Problem: Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/11/2015
Difficulty: ***
Review: ***
Solution:

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
    
private:
    bool isMatch(string &s, int i, string &p, int j) {
        int len_s = s.length();
        int len_p = p.length();
        if (i >= len_s && j >= len_p)
            return true;
        if (j >= len_p)
            return false;
            
        if (p[j+1] == '*') {
            int k = i - 1;
            do {
                ++k;
                if (isMatch(s, k, p, j+2))
                    return true;
            } while (k < len_s && (p[j] == s[k] || p[j] == '.'));
            
            return (k >= len_s && j+2 >= len_p);
        }
        
        return (i < len_s) && (s[i] == p[j] || p[j] == '.') && isMatch(s, i+1, p, j+1);
    }
};