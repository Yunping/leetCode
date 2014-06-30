/*
Problem: Regular Expression Matching
Source: https://oj.leetcode.com/problems/regular-expression-matching/
Difficulty: ***
Description: 
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

Note:
Recursive Solution by my own:
-If p is "x*..." like "a*..." or ".*...", then check "x*" match zero elements, 
one elements, ... If one of them is matched, return true, otherwise, return false.
-Otherwise, check *s and *p

Referred Solution:
The same with mine. But more clear and brief
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p) return false;
        
        while (*s != '\0' && *p != '\0') {
            // if p is "x*..." like "a*..." or ".*...", then check "x*" match 
            // zero elements, one elements, ...
            // If one of them is matched, return true, otherwise, return false
            if (*(p+1) == '*') {
                do {
                    if (isMatch(s, p+2))
                        return true;
                    if (*s == *p || *p == '.')
                        ++s;
                    else
                        return false;
                } while (*s != '\0');
            } else {
                if (*p == '.' || *p ==  *s) {
                    ++p;
                    ++s;
                } else
                    return false;
            }
        }
        
        // If s reach the end but p doesn't, we should check if the rest of p
        // is all like "a*b*...", if so, they can be ignored.
        while (*p != '\0') {
            if (*(p+1) == '*')
                p = p + 2;
            else
                break;
        }
        
        return *s == '\0' && *p == '\0';
    }
};