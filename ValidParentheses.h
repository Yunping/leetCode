/*
Problem: Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

==================================================================================================

Author: Yunping, qufang83@gmail.com
Date: 07/30/2014
Refactor: 10/24/2015
Difficulty: *^
Review: **
Solution: Use a stack
*/
class Solution {
private:
    bool isPair(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (!st.empty() && isPair(st.top(), c))
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};