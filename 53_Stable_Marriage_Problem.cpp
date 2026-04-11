#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        // code here
        int n = men.size();
        queue<int> q;
        for(int i = 0 ; i < n ; i++) q.push(i);
        
        vector<vector<int>> rank(n, vector<int> (n));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                rank[i][women[i][j]] = j;
            }
        }
        
        vector<int> m(n, -1), w(n, -1), next(n, 0);
        
        while(q.size() > 0){
            int i = q.front();
            q.pop();
            
            int woman = men[i][next[i]];
            next[i]++;
            
            if(w[woman] == -1){
                w[woman] = i;
                m[i] = woman;
            } else {
                int currpartner = w[woman];
                if(rank[woman][currpartner] > rank[woman][i]){
                    w[woman] = i;
                    m[i] = woman;
                    q.push(currpartner);
                    m[currpartner] = -1;
                }
                else {
                    q.push(i);
                }
            }
        }
        return m;
    }
};