/*
Problem: Multiply Strings
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/15/2014
Difficulty: **^
Review: ***
Solution: store num as a string.
*/
class Solution {
    typedef vector<int> bigNum;
    
    bigNum bigNumMultiply(bigNum& num1, bigNum& num2) {
        bigNum ret(num1.size() + num2.size(), 0);
        for (int i = 0; i < num1.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < num2.size(); ++j) {
                int multiple = (num1[i] * num2[j]);
                int sum = ret[i+j] + carry + multiple;
                ret[i+j] = sum % 10;
                carry = sum / 10;
            }
            if (carry)
                ret[i+num2.size()] = carry; 
        }
        
        return ret;
    }
    
    bigNum stringToBigNum(string s) {
        bigNum ret;
        for (char c:s)
            ret.insert(ret.begin(), c-'0');
        
        return ret;
    }
    
    string bugNumToString(bigNum &num) {
        string ret;
        if (num.empty()) return ret;
        
        // skip beginning zeros
        int i = num.size() - 1;
        while (i > 0 && num[i] == 0)
            --i;
        
        // insert from the end of the bigNum
        for (; i >=0; --i)
            ret.push_back(num[i]+'0');
        
        return ret;
    }
    
    
public:
    string multiply(string num1, string num2) {
        bigNum b_num1 = stringToBigNum(num1);
        bigNum b_num2 = stringToBigNum(num2);
        bigNum result = bigNumMultiply(b_num1, b_num2);
        
        return bugNumToString(result);
    }
};