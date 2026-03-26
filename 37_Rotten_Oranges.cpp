#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        
        queue<pair<int,int>> q;
        int m = mat[0].size(), n = mat.size();
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 2) q.push({i,j});
            }
        }
        
        q.push({-1,-1});
        int k = 0;
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i == -1){
                if(!q.empty()){
                    q.push({-1,-1});
                    k++; 
                } 
                continue;
            }
            
            if(i + 1 < n && mat[i+1][j] == 1) {
                q.push({i+1, j});
                mat[i+1][j] = 2;
            }
            if(j + 1 < m && mat[i][j+1] == 1) {
                q.push({i, j+1});
                mat[i][j+1] = 2;
            }
            if(i - 1 >= 0 && mat[i-1][j] == 1) {
                q.push({i-1, j});
                mat[i-1][j] = 2;
            }
            if(j - 1 >= 0 && mat[i][j-1] == 1) {
                q.push({i, j-1});
                mat[i][j-1] = 2;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 1) return -1;
            }
        }
        return k;
    }
};