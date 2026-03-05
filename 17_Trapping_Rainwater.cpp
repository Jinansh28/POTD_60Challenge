#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        
        int water = 0, n = arr.size();
        stack<int> s;
        
        int lmax = arr[0], rmax = arr[n-1];
        vector<int> left (n, 0), right (n, 0);
        left[0] = -1, right[n-1] = -1;
 
        for(int i = 1 ; i < n ; i++){
            if(arr[i] >= lmax){
                lmax = arr[i];
                left[i] = -1;
            }
            else {
                left[i] = lmax;
            }
        }
        
        for(int i = n-2 ; i >= 0 ; i--){
            if(arr[i] >= rmax){
                rmax = arr[i];
                right[i] = -1;
            }
            else {
                right[i] = rmax;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            if(left[i] != -1 && right[i] != -1) water += min(left[i], right[i]) - arr[i];
            // cout<<left[i]<<" ";
        }
        // cout<<endl;
        // for(int i : right) cout<<i<<" ";
        // cout<<endl;
        return water;
        
    }
};


//Optimal
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int water = 0, n = arr.size();
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        
        while(l < r){
            lmax = max(lmax, arr[l]);
            rmax = max(rmax, arr[r]);
            
            if(lmax < rmax){
                water += lmax - arr[l];
                l++;
            } else {
                water += rmax - arr[r];
                r--;
            }
        }
        return water;
    }
};