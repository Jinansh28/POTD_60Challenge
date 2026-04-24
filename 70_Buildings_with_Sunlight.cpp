#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = 1, m = arr[0];
        for(int i = 1; i < arr.size() ; i++){
            if(arr[i] >= m){
                m = arr[i];
                n++;
            }
        }
        return n;
    }
};