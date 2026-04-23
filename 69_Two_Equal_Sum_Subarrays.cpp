#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int sum = 0, n = arr.size();
        for(int i = 0; i < n ; i++) sum += arr[i];
        int a = 0;
        for(int i = 0 ; i < n ; i++){
            a += arr[i];
            if(a == sum - a) return true;
        }
        return false;
    }
};
