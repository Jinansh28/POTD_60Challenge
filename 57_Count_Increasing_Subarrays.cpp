#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size();
        bool a = false;
        int ans = 0, b = 0;
        for(int i = 1 ; i < n ; i++){
            if(arr[i] > arr[i-1]){
                if(!a) a = true;
                b++;
                ans += b;
            }
            else {
                a = false;
                b = 0;
            }
        }
        return ans;
    }
};
