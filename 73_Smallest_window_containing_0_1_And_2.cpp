#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.length();
        int l0 = -1, l1 = -1, l2 = -1;
        int minlen = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0') l0 = i;
            else if(s[i] == '1') l1 = i;
            else l2 = i;
            
            if(l1 != -1 && l2 != -1 && l0 != -1){
                minlen = min(minlen, max({l0, l1, l2}) - min({l0, l1, l2}) + 1);
            }
        }
        if(l1 != -1 && l2 != -1 && l0 != -1) return minlen;
        return -1;
    }
};
