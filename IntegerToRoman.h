/*
Problem: Integer to Roman
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/11/2015
Difficulty: **
Review: **
Solution: 
*/
class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1, 5, 10, 50, 100, 500, 1000, 5000};
        int chars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '?'};
        int size = sizeof(values)/sizeof(int);
        
        string ret;
        while (num > 0) {
            int i = 1;
            while (i < size) {
                if (num >= values[i-1] && num < values[i])
                    break;
                ++i;
            }
            
            if (i % 2) {
                //range like: [1,5), [10, 50).
                if (num < values[i] - values[i-1]) {
                    // range [1, 4), [10, 40)
                    int repeat = num / values[i-1];
                    while (repeat-- > 0) {
                        num -= values[i-1];
                        ret += chars[i-1];
                    }
                } else {
                    // range [4, 5), [40, 50)
                    ret += chars[i-1];
                    ret += chars[i];
                    num -= (values[i] - values[i-1]);
                }
            } else {
                // range like: [5, 10), [50, 100)
                if (num < values[i] - values[i-2]) {
                    // range like [5, 9), [50, 90)
                    int repeat = (num - values[i-1]) / values[i-2];
                    ret += chars[i-1];
                    num -= values[i-1];
                    while (repeat-- > 0) {
                        ret += chars[i-2];
                        num -= values[i-2];
                    }
                } else {
                    // range like [9, 10), [90, 100)
                    ret += chars[i-2];
                    ret += chars[i];
                    num -= (values[i] - values[i-2]);
                }
            }
        }
        
        return ret;
    }
};