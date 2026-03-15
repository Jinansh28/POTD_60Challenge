#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        vector<int> last(10, -1);
        int n = s.length();
        
        for(int i = 0 ; i < n ; i++) last[s[i] - '0'] = i;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 9 ; j > s[i] - '0' ; j--){
                if(i < last[j]){
                    swap(s[i], s[last[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};