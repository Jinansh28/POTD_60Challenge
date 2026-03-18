#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void helper(string a, vector<string> &ans, int k, int idx){
        if(k == 3){
            string b = a.substr(idx);
            int c = stoi(b);
            if(b[0] == '0' && b.length() > 1) return;
            if(c <= 255) ans.push_back(a);
            return;
        }
        
        for(int i = 1 ; i < 4 && idx + i < a.length() ; i++){
            string b = a.substr(idx, i);
            int c = stoi(b);
            if(b[0] == '0' && i != 1) continue;
            if(c <= 255){
                b = a.substr(0, idx + i) + "." + a.substr(idx + i);
                helper(b, ans, k + 1, idx + i + 1);
            }
        }
    }
    
    vector<string> generateIp(string &s) {
        vector<string> ans;
        if(s.length() > 12) return ans;
        helper(s, ans, 0 , 0);
        return ans;
    }
};