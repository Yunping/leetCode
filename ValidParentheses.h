/*
Problem: Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Date: 07/30/2014
Difficulty: *^
Review: **
Note: 
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairOf;
        pairOf['('] = ')';
        pairOf['['] = ']';
        pairOf['{'] = '}';
        
        stack<char> temp;
        
        size_t len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                temp.push(s[i]);
            else {
                if (temp.empty())
                    return false;
                char t = temp.top();
                if (pairOf[t] != s[i])
                    return false;
                temp.pop();
            }
        }
        
        return temp.empty();
    }
};