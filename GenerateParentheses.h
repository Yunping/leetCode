/*
Problem: Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Source: https://oj.leetcode.com/problems/generate-parentheses/

Author: Fang Qu
Date: 07/31/2014
Difficulty: **
Review: **
Solution: recursion.
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string result;
        vector<string> ret;
        generateParenthesis(n, n, result, ret);
        
        return ret;
    }
    
    void generateParenthesis(int left, int right, string &result, vector<string>& ret) {
        if (left == 0 && right == 0) {
            ret.push_back(result);
            return;
        }
        if (left > 0) {
            result.push_back('(');
            generateParenthesis(left-1, right, result, ret);
            result.pop_back();
        }
        
        if (left < right) {
            result.push_back(')');
            generateParenthesis(left, right-1, result, ret);
            result.pop_back();
        }
    }
};