#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i = 0 ; i < n ; i++){
            int a = houses[i][0], b = houses[i][1];
            for(int j = i + 1; j < n ; j++){
                int c = houses[j][0], d = houses[j][1];
                int e = abs(a-c) + abs(b-d);
                adj[j].push_back({e, i});
                adj[i].push_back({e, j});
            }
        }
        
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         cout<<adj[i][j].first<<adj[i][j].second<<" ";
        //     }
        //     cout<<endl;
        // }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<bool> vis(n, false);
        
        long long mst = 0;
        while(!pq.empty()){
            int c = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(vis[idx]) continue;
            vis[idx] = true;
            mst += c;
            
            for(auto j : adj[idx]){
                if(!vis[j.second]) pq.push({j.first, j.second});
            }
        }
        return mst;
        
    }
};