/*

Problem: String to Integer (atoi)
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Source: https://oj.leetcode.com/problems/string-to-integer-atoi/
Date: 0630/2014
Difficulty: *
Note: Take care of overflow.

*/
class Solution {
public:
    int atoi(const char *str) {
        long long ret = 0;
        const char *p = str;
        while (*p == ' ')
            ++p;
        
        int flag = 1;
        if (*p == '+' || *p == '-') {
            flag = (*p == '-') ? -1 : 1;
            ++p;
        }
        
        while (*p != '\0') {
            if (*p >= '0' && *p <= '9')
                ret = ret * 10 + flag * (*p - '0');
            else
                break;
            if (flag < 0 && ret <= INT_MIN)
                return INT_MIN;
            if (flag > 0 && ret >= INT_MAX)
                return INT_MAX;
            ++p;
        }
        
        return ret;
    }
};