#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        vector<int> ans(2,0);
        
        int minm = INT_MAX;
        
        int st = 0, end = arr2.size()-1;
        int s = 0, e = 0;
        
        while(st < arr1.size() && end >= 0){
            if(abs(arr1[st] + arr2[end] - x) < minm){
                minm = abs(arr1[st] + arr2[end] - x);
                s = st;
                e = end;
            }
            if(arr1[st] + arr2[end] > x) end--;
            else if(arr1[st] + arr2[end] == x){
                s = st;
                e = end;
                break;
            }
            else st++;
        }
        ans[0] = arr1[s];
        ans[1] = arr2[e];
        return ans;
        
    }
};