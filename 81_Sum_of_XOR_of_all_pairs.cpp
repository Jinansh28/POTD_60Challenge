#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long sum = 0;
        for(int i = 0 ; i < 32 ; i++){
            int o = 0, z = 0;
            for(int j = 0 ; j < n ; j++){
                if(arr[j] & 1 << i) o++;
                else z++;
            }
            sum += pow(2, i)*o*z;
        }
        return sum;
    }
};