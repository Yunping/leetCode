/*
Author: Yunping
Date: 07/02/2014
Difficulty: **

Problem: Integer to Roman
Description: Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

Solution:
First find the range that the num falls in,
if falls in ranges like 1~5, 10~50, etc
    if num is less then 4, 40, or 400
        repeat the first element of the range. 
        --such as "III", "XX", etc
    if num is equal or more then 4, 40, or 400
        append the first element of the range,
        append the second element of the range,
        then continue to convert the remains of num
        --such as "IV", "VX", etc.
if falls in ranges like 5~10, 50~100, etc
    if num is less than 9, 90, or 900
        append the first element of the range
        continue to convert the remains of num.
        -- such as "L", "D"
    if num is equal or more then 9, 90, or 900
        append the element before the first element of the range
        append the second element of the range
        continue to convert the remains
        --such as "IX", "XC"
*/
class Solution {
public:
    string intToRoman(int num) {
        int V[] = { 1, 5, 10, 50, 100, 500, 1000 };
        char S[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        int count = sizeof(V)/sizeof(int);
        
        string roman;
        while (num > 0) {
            int i = count - 1;
            while (i >= 0) {
                if (num >= V[i])
                    break;
                --i;
            }
            
            if (num == V[i]) {
                roman.push_back(S[i]);
                break;
            } 
            
            int m = num / V[i];
            if (m < 2) {    // 1: fall in (5-10), (50-100), or (500-1000)
                if (num + V[i-1] < V[i+1]) {    // 1.1: fall in (5-8], (50- 89], or (500-899]
                    roman.push_back(S[i]);
                    num -= V[i];
                } else {    // 1.2: fall in [9-9]), [90-99], or [900-999]
                    roman.push_back(S[i-1]);
                    roman.push_back(S[i+1]);
                    num -= (V[i+1] - V[i-1]);
                }
            } else { // 2: fall in (1-5), (10-50).
                if (m < 4) { // 2.1 fall in (1-3], (10-39], (100-399], or (1000-3999]
                    while (m > 0) {
                        roman.push_back(S[i]);
                        num -= V[i];
                        --m;
                    }
                } else { // 2.2: fall in [4-4], [40-49], [400-499]
                    assert(m == 4);
                    roman.push_back(S[i]);
                    roman.push_back(S[i+1]);
                    num -= (V[i+1] - V[i]);
                }
            }
        }
        
        return roman;
    }
};