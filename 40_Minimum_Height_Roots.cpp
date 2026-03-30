#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        
        if(V == 1){
            ans.push_back(0);
            return ans;
        }
        
        vector<vector<int>> e(V);
        vector<int> id(V, 0);
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0], v = edges[i][1];
            e[u].push_back(v);
            e[v].push_back(u);
            id[u]++;
            id[v]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i < id.size() ; i++){
            if(id[i] == 1) q.push(i);
        }
        
        while(V > 2){
            V -= q.size();
            int sz = q.size();
            
            while(sz > 0){
                int el = q.front();
                q.pop();
                
                for(int j : e[el]){
                    id[j]--;
                    if(id[j] == 1) q.push(j);
                }
                sz--;
            }
        }
        
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};