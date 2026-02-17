#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int ma = 0;
        for(int i = 0 ; i < arr.size() ; i++) ma = max(ma, max(arr[i][0], arr[i][1]));
        
        vector<int> f(ma+2, 0);
        
        for(int i = 0 ; i < arr.size() ; i++){
            f[arr[i][0]]++;
            f[arr[i][1] + 1]--;
        }
        int maxlen = 0, temp = 0;
        for(int i = 1 ; i <= ma ; i++){
            temp += f[i];
            maxlen = max(maxlen, temp);
        }
        return maxlen;
        
    }
};
