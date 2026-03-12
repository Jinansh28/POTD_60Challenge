#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // int count(int &m, int &n, int &x, int c, int sum){
    //     if(c > n) return 0;
    //     if(c == n && sum == x) return 1;
    //     // if(dp[sum] != -1) return dp[sum];
        
    //     int a = 0;
    //     for(int i = 1 ; i <= m ; i++){
    //         a += count(m, n, x, c+1, sum + i);
    //     }
    //     return a;
    // }
    
    int noOfWays(int m, int n, int x) {
        
        vector<int> dp(x + 1, 0);
        
        dp[0] = 1;
            
        for(int j = 0 ; j < n ; j++){
            vector<int> d = dp;
            dp.assign(x + 1, 0);
            for(int k = 0 ; k <= x ; k++){
                for(int i = 1 ; i <= m ; i++){
                    if(k + i <= x ) dp[k+i] += d[k];
                }
            }
        }
        return dp[x];
        
    }
};