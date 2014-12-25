/*
https://oj.leetcode.com/problems/implement-strstr/

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i, j, k;
        int n = strlen(haystack), m = strlen(needle);
        if (m == 0) return 0;
        for (i = m-1; i < n; i++) {
            if(haystack[i] == needle[m-1]) {
                j = m-1; k = i;
                while (j >= 0 && needle[j] == haystack[k]) {
                    j--; k--;
                }
                if (j < 0) return k+1;
            }
        }
        return -1;
    }
};
