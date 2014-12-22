/*
https://oj.leetcode.com/problems/longest-palindromic-substring/

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int res = 1, n = s.length();
        int l, r, k, res_i=0;
        for (int i = 0; i < n; i++) {
            l = i-1; r = i+1; k = 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                k +=2;
                l--; r++;
            }
            if (res < k) {
                res = k;
                res_i = l+1;
            }
            l = i; r = i+1; k = 0;
            while (l >= 0 && r < n && s[l] == s[r]) {
                k +=2;
                l--; r++;
            }
            if (res < k) {
                res = k;
                res_i = l+1;
            }
        }
        return s.substr(res_i, res);
    }
};
