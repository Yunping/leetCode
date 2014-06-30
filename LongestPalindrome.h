/*
Problem: Longest Palindromic Substring
Source: https://oj.leetcode.com/problems/longest-palindromic-substring/
Date: 06/29/2014
Note: 看到此题目后，想到应用动态规划
第一个思路是这样的：
max <- 0
for i <- (0...len),
    for j <- (0, i) and i - j > max
        judge whether {s[j]..s[i]} is palindrome
        if yes, then update max and break

这种方法没有利用好动态规划的优点，不能利用已有的计算结果推算当前的计算

第二个思路是采用二维的动态规划，思路如下
P[i][j]表示{s[i]...[s[j]}是否为palindrome,
P[i][j] = {
    true, if i == j
    s[i] == s[j], if j - i == 1
    P[i+1][j-1] && s[i] == s[j], if j - i > 1
}
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 0) return "";
        
        bool isPalindrome[1000][1000] = { false };
        int maxLen = 1;
        int maxIndex = 0;

        // iterate by diagonals
        for (int line = 0; line < len; ++line) {
            for (int i = 0; i < len - line; ++i) {
                int j = line + i;
                if (line == 0) {
                    isPalindrome[i][j] = true;
                } else if (line == 1 && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                } else if (isPalindrome[i+1][j-1] && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                } else
                    isPalindrome[i][j] = false;
                    
                if (isPalindrome[i][j] && line + 1 > maxLen) {
                    maxLen = line + 1;
                    maxIndex = i;
                }
            }
        }
        
        return s.substr(maxIndex, maxLen);
    }
};