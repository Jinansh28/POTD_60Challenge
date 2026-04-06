#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countStrings(int n) {
        int prev2 = 1;
        int prev1 = 1;
        for(int i = 1 ; i <= n ; i++){
            int f = prev2 + prev1;
            prev2 = prev1;
            prev1 = f;
        }
        return prev1;
    }
};

// 0000 0001 0010 0100 0101 1000 1001 1010 10000 10001 10010 10100 10101
// 0011 0110 0111 1011 1100 1101 1110 1111 10011 10110 10111 11000