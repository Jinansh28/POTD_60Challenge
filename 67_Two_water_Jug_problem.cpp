#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSteps(int m, int n, int d) {
        // Code here
        if(d % gcd(m,n) != 0) return -1;
        if(d > max(m, n)) return -1;
        int a = pour(m, n, d);
        int b = pour(n, m, d);
        return min(a,b);
        
    }
    int pour(int fromCap, int toCap, int d){
        int from = fromCap, to = 0;
        int step = 1;
        while(from != d && to != d){
            int temp = min(from, toCap - to);
            to += temp;
            from -= temp;
            step++;
            
            if(from == d || to == d) break;
            
            if(from == 0){
                from = fromCap;
                step++;
            }
            if(to == toCap){
                to = 0;
                step++;
            }
        }
        return step;
    }
};