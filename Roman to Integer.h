/*
Author: Yunping
Date: 07/02/2014
Difficulty: *

Problem: Roman to Integer
Description: 
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

Solution: Add/Minus values from right to left.
*/
class Solution {
public:
    int charToValue(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    
    int romanToInt(string s) {
        int ret = 0;
        int len = s.length();
        int lastValue = 0;
        for (int i = len - 1; i >= 0; --i) {
            int value = charToValue(s[i]);
            if (value >= lastValue)
                ret += value;
            else
                ret -= value;
            lastValue = value;
        }
        
        return ret;
    }
};