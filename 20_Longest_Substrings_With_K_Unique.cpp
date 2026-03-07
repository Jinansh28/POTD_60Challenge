#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        unordered_set<char> se;
        vector<int> ch(26,-1);
        int ans = -1, prev = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(se.size() == k && se.find(s[i]) == se.end()){
                int minm = INT_MAX;
                char cha;
                for(auto &j : se){
                    if(minm > ch[j-97]){
                        minm = ch[j-97];
                        cha = j;
                    }
                }
                ans = max(i - prev, ans);
                se.erase(cha);
                prev = minm + 1;
            }
            se.insert(s[i]);
            ch[s[i] - 97] = i;
        }
        if(se.size() == k) ans = max(ans, n - prev);
        return ans;
    }
};