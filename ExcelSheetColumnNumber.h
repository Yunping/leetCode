/*
Problem: Excel Sheet Column Number

Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 07/25/2015
Difficulty: **
Review: **^
Solution: (Own) Similiar with 26-base number, but a little bit different. A is 1 instead of 0.
*/
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            ret = ret * 26 + (s[i] - 'A' + 1);
        }
        return ret;
    }
};