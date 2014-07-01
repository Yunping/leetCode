/*
Author: Yunping, artbupt@gmail.com
Date:	01/01/2014

Problem:	Valid Number
Difficulty:	Medium
Source:		http://oj.leetcode.com/problems/valid-number/
Description:
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 

Solutions:

*/

class Solution {
public:
    bool isNumber(const char *s) {
        // +1.0
        // 1e
        // 1e3
        // 1e-3
        // "   1.0e-3"
        // "   1.0e+3   "
        // 1e3e1
        // 1.0.1
        // 3.       true
        // "."      false
        // "e"      false
 
        if (!s || strlen(s) == 0) return false;
        
        const char* p = s;
        while (*p == ' ')
            ++p;
        if (*p == '+' || *p == '-')
            ++p;
        
        // check the pure digits, "123", "1.01", etc.
        bool hasNumber = false;
        bool canHasDot = true;
        while (*p != '\0') {
            if (*p >= '0' && *p <= '9') {
                hasNumber = true;
            } else {
                if (*p == '.') {
                    if (canHasDot)
                        canHasDot = false;
                    else
                        break;
                }
                else
                    break;
            }
            ++p;
        }
        
        // return false if it is "1.0.1", "."
        if (!hasNumber || (!canHasDot && *p == '.')) return false;
        
        // check if it is scientist number
        bool isScientist = false;
        if (*p == 'e') {
            ++p;
            if (*p == '+' || *p == '-')
                ++p;
            while (*p != '\0') {
                if (*p >= '0' && *p <= '9') {
                    isScientist = true;
                    ++p;
                }
                else
                    break;
            }
            
            if (!isScientist)
                return false;
        }
        
        // trim trail spaces
        while (*p != '\0' && *p == ' ')
            ++p;
        
        return *p == '\0';
    }
};