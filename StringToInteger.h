/*
Problem: String to Integer (atoi)
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

===============================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/07/2015
Difficulty: *
Review: **
Solution:
Cases:
    1. Begining zeros and spaces
    2. Sign: +/-
    3. Overflow: Return INT_MAX/INT_MIN
    4. Invalid char: Return current result
*/
class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        if (!len) return 0;

        int start = 0;
        
        // skim the begining zeros/spaces
        while ((str[start] == '0' || str[start] == ' ') && start < len)
            ++start;
        
        // determine sign
        char sign = 1;
        if (str[start] == '-') {
            sign = -1;
            ++start;
        } else if (str[start] == '+') {
            ++start;
        }
        
        long long ret = 0;
        for (int i = start; i < len; ++i) {
            if (str[i] < '0' || str[i] > '9')
                break;
            ret = ret * 10 + (str[i] - '0') * sign;
            if (ret > INT_MAX)
                return INT_MAX;
            if (ret < INT_MIN)
                return INT_MIN;
        }
        
        return ret;
    }
};