/*
Author: Yunping Qu, qufang83@gmail.com
Date: Jan 6, 2014
Update: Jan 6, 2014
Problem: Plus One
Difficulty: Easy
Source: http://oj.leetcode.com/problems/plus-one/
Notes:
Given a number represented as an array of digits, plus one to the number.

Solution: ...
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        size_t sz = digits.size();
        int extra = 1;
        for (int i = sz - 1; i >= 0; --i) {
            int sum = digits[i] + extra;
            digits[i] = sum % 10;
            extra = sum / 10;
            if (!extra)
                break;
        }
        
        if (extra)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};