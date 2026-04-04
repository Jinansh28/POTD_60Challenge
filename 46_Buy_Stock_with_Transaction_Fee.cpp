#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int ps = 0, pb = -1 * arr[0];
        for(int i = 1 ; i < arr.size(); i++){
            int bs = max(pb, ps - arr[i]);
            int ss = max(ps, arr[i] + pb - k);
            pb = bs;
            ps = ss;
        }
        return ps;
    }
};