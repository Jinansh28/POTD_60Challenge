#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool cycle(vector<bool> &vis, vector<bool> &rec, vector<vector<int>> &pre, int i){
        vis[i] = true;
        rec[i] = true;
        
        for(int j : pre[i]){
            if(!vis[j]){
                if(cycle(vis, rec, pre, j)) return true;
            } else if(rec[j]) return true;
        }
        rec[i] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>> pre(n);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            pre[u].push_back(v);
        }
        
        vector<bool> vis(n, false) , rec(n, false);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(cycle(vis, rec, pre, i)) return false;
            }
        }
        return true;
    }
};