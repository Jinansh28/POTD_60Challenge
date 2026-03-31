#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &it : edges){
            adj[it[0]].push_back({it[2], it[1]}); 
            adj[it[1]].push_back({it[2], it[0]});
        }
        
        const int MOD = 1e9 + 7;
        
        vector<long long> dis(V, LLONG_MAX);
        vector<int> ways(V, 0);
        
        dis[0] = 0;
        ways[0] = 1;
        
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(dist > dis[u]) continue;
            
            for(auto &it : adj[u]){
                long long wt = it.first;
                int v = it.second;
                
                if(dis[u] + wt < dis[v]){
                    dis[v] = dis[u] + wt;
                    ways[v] = ways[u];
                    pq.push({dis[v], v});
                }
                else if(dis[u] + wt == dis[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[V-1];
    }
};