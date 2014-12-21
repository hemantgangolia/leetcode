/*
https://oj.leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
    stack<int> stk;
    stack<int> min_stk;
public:
    
    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.top()) {
            min_stk.push(x);
        }
    }

    void pop() {
        if (!stk.empty()) {
            if (stk.top() == min_stk.top()) {
                min_stk.pop();
            }
            stk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};