/*
https://oj.leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        vector<bool> w (len,0);
        
        for (int i = 0; i < len; i++) {
            if (dict.find(s.substr(0,i+1)) != dict.end()) {
                w[i] = true;
            }
            if (w[i]) {
                for (int j = i; j < len; j++) {
                    if (dict.find(s.substr(i+1, j-i)) != dict.end()) {
                        w[j] = true;
                    }
                }
            }   
            
        }
        return w[len-1];
    }
};