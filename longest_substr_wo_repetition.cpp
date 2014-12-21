/*
https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> my_map;
        
        int res = 0, temp = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (my_map.find(c) != my_map.end() && i-my_map[c] <= temp) {
                temp = i-my_map[c];
                my_map[c] = i;
            } else {
                temp++;
                my_map[c] = i;
            }
            res = max(res, temp);
        }
        return res;
    }
};