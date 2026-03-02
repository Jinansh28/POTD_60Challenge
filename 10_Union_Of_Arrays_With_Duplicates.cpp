#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;
        
        for(int i = 0; i < a.size() ; i++) s.insert(a[i]);
        for(int i = 0; i < b.size() ; i++) s.insert(b[i]);
        
        vector<int> ans;
        for(int i : s) ans.push_back(i);
        return ans;
    }
};