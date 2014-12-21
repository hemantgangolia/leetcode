#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>

using namespace std;
void getNextWords(string str, vector<string> &my_set, set<string> &dict) {
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
    
    int ladderLength(string start, string end, set<string> &dict) {
        if (valid(start,end)){return 2;}
        if (start == end) return 0;
        queue<pair<string, int> > left, right;
        left.push(pair<string, int> (start, 0));
        right.push(pair<string, int> (end, 0));
        vector<string> temp;
        
        set<string>::const_iterator got = dict.find(start);
        if (got != dict.end()) {
            dict.erase(start);
        }
        got = dict.find(end);
        if (got != dict.end()) {
            dict.erase(end);
        }
        
        map<string, int> l_map, r_map;
        for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
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

int main () {
    set<string> dict;
    dict.insert("b");
    set<string> temp;
    // getNextWords("a", temp, dict);
    // for (set<string>::iterator it = temp.begin(); it != temp.end(); it++) {
    //     cout << *it << endl;
    // }
    dict.insert("a");
    dict.insert("c");

    cout << ladderLength("a", "c", dict) << endl;
    return 0;
}