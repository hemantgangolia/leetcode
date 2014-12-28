/*
https://oj.leetcode.com/problems/excel-sheet-column-number/

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/
class Solution {
public:
    int titleToNumber(string s) {
        return s.empty() ? 0 : ((s[s.length()-1]-'A'+1) + 26*(titleToNumber(s.substr(0, s.length()-1))));
    }
};
