/*
Problem: Evaluate Reverse Polish Notation
Source: https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
Difficulty: **
Date: 06/29/2014
Note: 此题一次做出
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator it = tokens.begin();
        vector<string>::iterator it_end = tokens.end();
        stack<int> s;
        while (it != it_end) {
            if (*it == "+") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int result = op2 + op1;
                s.push(result);
            }
            
            else if (*it == "-") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int result = op2 - op1;
                s.push(result);
            }
            
            else if (*it == "*") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int result = op2 * op1;
                s.push(result);
            }
            
            else if (*it == "/") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int result = op2 / op1;
                s.push(result);
            }
            
            else {
                s.push(atoi((*it).c_str()));
            }
            
            ++it;
            
        }
        
        return s.top();
    }
};