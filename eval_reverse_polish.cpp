/*
https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].compare("+") == 0) {
                    int a = s.top(); s.pop();
                    int b = s.top(); s.pop();
                    s.push(a+b);
            } else if (tokens[i].compare("-") == 0) {
                    int a = s.top(); s.pop();
                    int b = s.top(); s.pop();
                    s.push(b-a);
            } else if (tokens[i].compare("*") == 0) {
                    int a = s.top(); s.pop();
                    int b = s.top(); s.pop();
                    s.push(a*b);
            } else if (tokens[i].compare("/") == 0) {
                    int a = s.top(); s.pop();
                    int b = s.top(); s.pop();
                    s.push(b/a);
            } else {
                    s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};
