#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n < 2) return n;
        
        int a = 1;
        while(n > 1 && n % 2 == 0){
            n = n / 2;
            a++;
        }
        if(n == 1) return a;
        return -1;
    }
};
