#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int a = -1, z = 0, n = arr.size();
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == 0){
                z++;
                if(a == -1) a = i;
            }
            else {
                if(a != -1) arr[a++] = arr[i];
            }
        }
        for(int i = z ; i > 0 ; i--){
            arr[n - i] = 0;
        }
        
    }
};