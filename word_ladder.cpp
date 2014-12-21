/*
https://oj.leetcode.com/problems/word-ladder/

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
public:
    void getNextWords(string str, vector<string> &my_set, unordered_set<string> &dict) {
        string temp = str;
        for (int i = 0; i < str.length(); i++) {
            for (char j = 'a'; j <= 'z'; j++) {
                temp = str;
                temp[i] = j;
                if (dict.find(temp) != dict.end()) {
                    my_set.push_back(temp);
                }
            }
        }
    }
    
    bool valid(string s1,string s2){
        bool flag=false;
        for (int i=0;i<s1.size();i++){
            if (s1[i]!=s2[i]){
                if (flag==true){return false;}
                else{flag=true;}
            }
        }
        return true;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (valid(start,end)){return 2;}
        if (start == end) return 0;
        queue<pair<string, int> > left, right;
        left.push(pair<string, int> (start, 0));
        right.push(pair<string, int> (end, 0));
        vector<string> temp;
        
        unordered_set<string>::const_iterator got = dict.find(start);
        if (got != dict.end()) {
            dict.erase(start);
        }
        got = dict.find(end);
        if (got != dict.end()) {
            dict.erase(end);
        }
        
        map<string, int> l_map, r_map;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            l_map[*it] = r_map[*it] = 0;
        }
        
        while (!left.empty() && !right.empty()) {
            pair<string, int> lsi = left.front(), rsi = right.front();
            left.pop(); right.pop();
            
            if (lsi.first==rsi.first) {
                return lsi.second+rsi.second;
            }
            
            temp.clear();
            getNextWords(lsi.first, temp, dict);
            for (int i = 0; i < temp.size(); i++) {
                if (!l_map[temp[i]] ) {
                    l_map[temp[i]] = lsi.second+1;
                    if (r_map[temp[i]]) return l_map[temp[i]] + r_map[temp[i]]+1;
                    left.push(pair<string,int> (temp[i], lsi.second+1));
                }
            }
            
            temp.clear();
            getNextWords(rsi.first, temp, dict);
            for (int i = 0; i < temp.size(); i++) {
                if (!r_map[temp[i]]) {
                    r_map[temp[i]] = rsi.second+1;
                    if (l_map[temp[i]]) return l_map[temp[i]] + r_map[temp[i]]+1;
                    right.push(pair<string,int> (temp[i], rsi.second+1));
                }
            }
        }
        return 0;
    }
};