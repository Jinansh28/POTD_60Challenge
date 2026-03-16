#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size(), a = 0;
        
        stack<int> s;
        s.push(n-1);
        vector<int> right(n, n), left(n, -1);
        
        for(int i = n - 2 ; i >= 0 ; i--){
            
                while(!s.empty() && arr[i] <= arr[s.top()]) s.pop();
                if(!s.empty()) right[i] = s.top();
                else right[i] = n;
            
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        s.push(0);
        
        for(int i = 1 ; i < n ; i++){
            
                while(!s.empty() && arr[i] < arr[s.top()]) s.pop();
                if(!s.empty()) left[i] = s.top();
                else left[i] = -1;
            
            s.push(i);
        }
        
        for(int i = 0 ; i < n ; i++){
            a += (right[i] - i)*(i - left[i]) * arr[i];
        }
        return a;
    }
};