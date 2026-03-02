#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int ans1 = 0, ans2 = 0, ans = 0;
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i = 0 ; i < a1.size() ; i++){
            ans1 += a1[i];
            ans2 += a2[i];
            int dif = ans2 - ans1;
            if(m.find(dif) != m.end()){
                ans = max(ans, i - m[dif]);
            } else m[dif] = i;
            
        }
        return ans;
    }
};