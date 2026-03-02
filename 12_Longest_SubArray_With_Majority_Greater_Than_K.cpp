#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        
        unordered_map<int,int> m;
        
        int ans = 0, ct = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] > k) ct++;
            else ct --;
            
            if(ct > 0) ans = max(ans, i+1);
            else if(m.find(ct-1) != m.end()) ans = max(ans, i-m[ct-1]);
            
            if(m.find(ct) == m.end()) m[ct] = i;
        }
        return ans;
        
    }
};