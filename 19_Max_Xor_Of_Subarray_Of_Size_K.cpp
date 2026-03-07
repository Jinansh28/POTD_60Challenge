#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        
        for(int i = 1 ; i < n ; i++){
            arr[i] = arr[i] ^ arr[i-1];
        }
        
        int maxm = arr[k-1], a = 0;;
        for(int i = k ; i < n ; i++){
            maxm = max(maxm, arr[i] ^ arr[a]);
            a++;
        }
        return maxm;
    }
};