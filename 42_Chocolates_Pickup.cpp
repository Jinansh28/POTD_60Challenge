#include<bits/stdc++.h>
using namespace std;

// Memoization

// class Solution {
//   public:
//     int f(int i, int j1, int j2,vector<vector<int>> &grid, int &m, int &n,vector<vector<vector<int>>> &dp){
//         if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
        
//         if(i == n-1){
//             if(j1 == j2) return grid[i][j1];
//             else return grid[i][j1] + grid[i][j2];
//         }
        
//         if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
//         int maxm = -1e8;
//         for(int k = -1 ; k <= 1 ; k++){
//             for(int l = -1 ; l <= 1 ; l++){
//                 int value = 0;
//                 if(j1 != j2) value = grid[i][j1] + grid[i][j2];
//                 else value = grid[i][j1];
//                 value += f(i+1, j1+k, j2+l, grid, m, n, dp);
//                 maxm = max(maxm, value);
//             }
//         }
//         return dp[i][j1][j2] = maxm;
//     }
//     int maxChocolate(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
        
//         vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1)));
        
//         return f(0,0,m-1,grid,m,n,dp);
//     }
// };


// Tabulation