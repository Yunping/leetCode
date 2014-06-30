/*
Problem: Reverse Integer
Source: https://oj.leetcode.com/problems/reverse-integer/
Difficulty: *^
Note: One time pass in 15 minutes
唯一需要注意的地方是防止溢出。使用一个long long类型的变量存储返回值，
计算过程中发现溢出即停止计算
*/
class Solution {
public:
    int reverse(int n) {
        long long ret = 0;
        bool negative = n < 0;
        while (n) {
            ret = ret * 10 + n % 10;
            if ((negative && ret < INT_MIN) || (!negative && ret > INT_MAX))
                break;
            n = n / 10;
        }
        
        return ret;
    }
};