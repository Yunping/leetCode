/*
Problem: Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Author: Yunping
Date: 08/19/2014
Difficulty: ***^
Review: ***
Solution: Mark all pairs of parentheses with ' ', then count the maximum continous count of spaces.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<size_t> leftPoses;
        size_t sz = s.length();
        for (size_t i = 0; i < sz; ++i) {
            if (s[i] == '(')
            	leftPoses.push(i);
            else {
            	if (!leftPoses.empty()) {
            		s[leftPoses.top()] = s[i] = ' ';
            		leftPoses.pop();
            	}
            }
        }

        int max = 0;
        int cur = 0;
        for (size_t i = 0; i < sz; ++i) {
        	if (s[i] == ' ') {
        		if (i > 0 && s[i-1] == ' ')
        			cur += 1;
        		else
        			cur = 1;

        		if (cur > max)
        			max = cur;
        	}
        }

        return max;
    }
};