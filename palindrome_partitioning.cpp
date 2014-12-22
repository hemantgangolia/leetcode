/*
https://oj.leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
class Solution {
public:
    
    void dfs(string s, int index, vector<vector<int> > & is_palin, vector<string> & temp, vector<vector<string> > & res) {
        if (index == s.length()) {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (is_palin[index][i] == 1) {
                temp.push_back(s.substr(index, i-index+1));
                dfs(s, i+1, is_palin, temp, res);
                temp.pop_back();
            }
        }a
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<vector<int> > is_palin(n, vector<int> (n, 0));
        
        int l, r;
        for (int i = 0; i < n; i++) {
            is_palin[i][i] = 1;
            
            l = i-1; r = i+1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                is_palin[l][r] = 1;
                l--; r++;
            }

            l = i; r = i+1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                is_palin[l][r] = 1;
                l--; r++;
            }
        }    
        
        vector<string> temp;
        vector<vector<string> > res;
        dfs(s, 0, is_palin, temp, res);
        return res;
    }
};
