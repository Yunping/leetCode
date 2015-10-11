/*
Problem: Reverse Integer
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/07/2015
Difficulty: *
Review: **
Note:
1. 唯一需要注意的是如何判断溢出，本题使用long long类型来存储计算结果，随时检查int的溢出情况
2. 取模和取余：
％一般是取余的意思，也就是商向0方向舍入
取模是商向负无穷方向舍入
*/
class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while (x) {
            int v = x % 10;
            ret = ret * 10 + v;
            if (ret < INT_MIN || ret > INT_MAX)
                return 0;
            x = x / 10;
        }
        
        return ret;
    }
};