#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0, j = n-1;
        while(i <= j){
            if(arr[i] == 1) swap(arr[i], arr[j--]);
            else i++;
        }
    }
};