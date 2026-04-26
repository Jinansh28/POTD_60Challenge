#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        vector<int> ans;
        unordered_set<int> s, s1;
        for(int i = 0 ; i < a.size() ; i++) s.insert(a[i]);
        for(int i = 0 ; i < b.size() ; i++) s1.insert(b[i]);
        for(int i = 0 ; i < c.size() ; i++){
            if(ans.size() > 0 && ans[ans.size()-1] == c[i]) continue; 
            if(s.find(c[i]) != s.end() && s1.find(c[i]) != s1.end()) ans.push_back(c[i]);
        }
        return ans;
    }
};