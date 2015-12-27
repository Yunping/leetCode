/*
Problem: Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

===========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/06/2015
Difficulty: **
Review: **
Solution:
*/
class Solution {
private:
    void doGenerate(int left, int right, string &result, vector<string> &ret) {
        if (left == 0 && right == 0) {
            ret.push_back(result);
            return;
        }
        
        if (left <= right) {
            if (left > 0) {
                result.push_back('(');
                doGenerate(left-1, right, result, ret);
                result.pop_back();
            }
            
            if (right > 0) {
                result.push_back(')');
                doGenerate(left, right-1, result, ret);
                result.pop_back();
            }
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n > 0) {
            string result;
            doGenerate(n, n, result, ret);
        }
        
        return ret;
    }
};