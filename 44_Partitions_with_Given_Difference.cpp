#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int f(int i, int sum, vector<vector<int>> &dp, vector<int> &num){
        if(i == 0){
            if(sum == 0 && num[0] == 0) return 2;
            if(sum == 0 || sum == num[0]) return 1;
            return 0;
        }
        
        if(dp[i][sum] != -1)return dp[i][sum];
        int nottake = f(i-1, sum, dp, num);
        int take = 0;
        if(num[i] <= sum) take = f(i-1, sum - num[i], dp, num);
        return dp[i][sum] = take + nottake;
    }
    
    int totalways(vector<int> &arr, int k){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (k+1 , -1));
        return f(n-1, k, dp, arr);
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = 0;
        for(int i = 0 ; i < arr.size() ; i++) sum += arr[i];
        if(sum - diff < 0 || (sum - diff) % 2 == 1) return 0;
        return totalways(arr, (sum - diff)/2);
    }
};