#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        vector<string> ans;
        int m = pow (2, n);
        for(int i = 0 ; i < m ; i++){
            int a = i ^ i/2;
            string str = bitset<32> (a).to_string();
            str = str.substr(32-n);
            ans.push_back(str);
        }
        return ans;
    }
};