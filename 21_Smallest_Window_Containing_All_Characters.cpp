#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        unordered_map<char,int> m;
        int need = p.length(), n = s.length();
        for(char c : p) m[c]++;
        
        int l = 0, start = 0, minlen = INT_MAX;
        for(int r = 0 ; r < n ; r++){
            if(m[s[r]] > 0) need--;
            m[s[r]]--;
            
            while(need == 0){
                if(minlen > r-l+1){
                    minlen = r-l+1;
                    start = l;
                }
                
                m[s[l]]++;
                if(m[s[l]] > 0) need++;
                l++;
            }
        }
        if(minlen == INT_MAX) return "";
        return s.substr(start, minlen);
    }
};