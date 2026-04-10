#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rec(vector<int> &arr, int target, int i, vector<vector<int>> &dp, int &sum){
        if(i < 0){
            if(target == 0) return 1;
            return 0;
        }
        if(target > sum || target < -sum) return 0;
        if(dp[i][target+sum] != -1) return dp[i][target+sum];
        
        int plus =rec(arr, target-arr[i], i-1, dp, sum);
        int minus = rec(arr, target+arr[i], i-1, dp, sum);
        return dp[i][target+sum] = plus + minus;
    }
    int totalWays(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++) sum += arr[i];
        vector<vector<int>> dp(n, vector<int> (2*sum + 1,-1));
        return rec(arr, target, n-1, dp, sum);
    }
};