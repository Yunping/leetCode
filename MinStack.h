/*
Problem: Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/10/2014
Difficulty: *
Review: *
Solution: Two stacks...
*/
class MinStack {
public:
    void push(int x) {
        data.push(x);
        if (minData.empty() || minData.top() >= x)
            minData.push(x);
    }

    void pop() {
        if (data.empty())
            return;
        int x = data.top();
        data.pop();
        if (x == minData.top())
            minData.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minData.top();   
    }
    
private:
    stack<int> data;
    stack<int> minData;
};