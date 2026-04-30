#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector <int> ans(n, -1);
        
        for(int i = 0 ; i < n ; i++){
            pq.push(arr[i]);
            if(pq.size() == k) ans[i] = pq.top();
            if(pq.size() > k){
                pq.pop();
                ans[i] = pq.top();
            }
        }
        return ans;
    }
};