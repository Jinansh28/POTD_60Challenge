#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int ans = 0, zero = 0, one = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(!arr[i]) zero++;
            else {
                zero--;
                one++;
            }
            ans = max(ans, zero);
            if(zero < 0) zero = 0;
        }
        return ans + one;
    }
};