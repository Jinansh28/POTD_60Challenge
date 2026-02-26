#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int ans = 0;
        for(int i = 0 ; i < citations.size() ; i++){
            ans = max(ans, min(citations[i], n-i));
        }
        return ans;
    }
};