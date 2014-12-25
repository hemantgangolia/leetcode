/*
https://oj.leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
class Solution {
public:
    void reverseWords(string &s) {
        string word = "";
        string res = "";
        int i = 0, len = s.length();
        
        while (i < len) {
            if (s[i] == ' ' && word.empty()) {
                i++;
                continue;
            }
            if (s[i] == ' ' && !word.empty()) {
                res = word + " " + res;
                word = "";
                i++;
                continue;
            } 
            if (s[i] != ' ') {
                word = word + s[i];
                i++;
                continue;
            }
        }
        if (!word.empty()) {
            res = word + " " + res;
        }
        s = res.substr(0, res.length()-1);
    }
};
