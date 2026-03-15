#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int a = 0, n = arr.size();
        
        stack<int> s;
        s.push(n-1);
        vector<int> right(n, n);
        
        for(int i = n - 2 ; i >= 0 ; i--){
            if(arr[i] > arr[s.top()]) right[i] = s.top();
            else {
                while(!s.empty() && arr[i] <= arr[s.top()]) s.pop();
                if(!s.empty()) right[i] = s.top();
                else right[i] = n;
            }
            s.push(i);
        }
        
        // for(int i : right) cout<<i<<" ";
        
        for(int i = 0 ; i < n ; i++) a += right[i] - i;
        
        return a;
    }
};