/*
https://oj.leetcode.com/problems/length-of-last-word/

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int i = len-1;
        while (s[i] == ' ') --i;
        int count = 0;
        while (i >= 0 && s[i] != ' ') {
            ++count;
            --i;
        }
        return count;
    }
};
