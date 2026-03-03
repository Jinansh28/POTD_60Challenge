#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        unordered_map<char,char> m;
        unordered_map<char,char> m1;
        for(int i = 0 ; i < s1.length() ; i++){
            if(m.find(s1[i]) == m.end() && m1.find(s2[i]) == m1.end()){
                m[s1[i]] = s2[i];
                m1[s2[i]] = s1[i];
            } 
            if(m[s1[i]] != s2[i] || m1[s2[i]] != s1[i]) return false;
        }
        return true;
        
    }
};