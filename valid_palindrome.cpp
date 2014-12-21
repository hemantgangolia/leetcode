/*
https://oj.leetcode.com/problems/valid-palindrome/

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isAlpha(char c) {
        int x = c-'a';
        int t = c-'0';
        if ((x >= 0 && x <= 25) || (t >= 0 && t <= 9)) return true;
        else return false;
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while (i<j) {
            while (i < j && !isAlpha(tolower(s[i]))) {
                i++;
            }
            while (i < j && !isAlpha(tolower(s[j]))) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;j--;
        }    
        return true;
    }
    
};