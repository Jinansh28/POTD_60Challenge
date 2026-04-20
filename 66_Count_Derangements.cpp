#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int derangeCount(int n) {
        // code here
        if(n <= 1) return 0;
        int prev1 = 0, prev = 1;
        for(int i = 2 ; i < n ; i++){
            int temp = (i)*(prev1 + prev);
            prev1 = prev;
            prev = temp;
        }
        return prev;
    }
}; 