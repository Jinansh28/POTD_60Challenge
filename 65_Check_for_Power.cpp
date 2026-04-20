#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if(y == 1) return true;
        if(x == 1){
            return false;
        }
        if(x > y) return false;
        while(y > x){
            if(y % x != 0) return false;
            y = y / x;
        }
        return x == y ;
    }
};