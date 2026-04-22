#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        for(int i = 1 ; i < n ; i++) arr[i] += arr[i-1];
        
        vector<int> ans(queries.size());
        for(int i = 0 ; i < queries.size() ; i++){
            int l = queries[i][0], r = queries[i][1];
            int sum;
            if(l == 0) sum = arr[r];
            else sum = arr[r] - arr[l-1];
            ans[i] = sum/(r-l+1);
        }
        return ans;
    }
};