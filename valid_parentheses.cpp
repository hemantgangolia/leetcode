/*
https://oj.leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len%2){
            return false;
        }
        if (len == 0) {
            return true;
        }
        stack<char> stk;
        stk.push(s[0]);
        for (int i = 1; i < len; i++) {
            if (s[i] == ']' && stk.top() != '[') return false;
            else if (s[i] == '}' && stk.top() != '{') return false;
            else if (s[i] == ')' && stk.top() != '(') return false;
            else if (s[i] == '(' || s[i] == '{' || s[i] == '[') { 
                stk.push(s[i]);
            } else {
                stk.pop();
            }
        }
        return stk.empty();
    }
};