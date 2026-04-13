#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;
        for(int i = 0 ; i < a.size() ; i++) s.insert(a[i]);
        vector<int> ans;
        for(int i = 0 ; i < b.size() ; i++){
            if(s.find(b[i]) != s.end()){
                ans.push_back(b[i]);
                s.erase(b[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};