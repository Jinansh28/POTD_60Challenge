#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        if(n == 1) return k;
        if(n == 2) return k*k;
        int prev1 = k*k, prev2 = k;
        for(int i = 3 ; i <= n ; i++){
            int temp = (k-1)*(prev1 + prev2);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};