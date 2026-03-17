#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int b = 0, n = arr.size(), count = 0;
        unordered_set<int> s;
        
        for(int i = 0 ; i < n ; i++){
            if(s.find(i - k) != s.end()) count --;
            if((arr[i] == 0 && count % 2 == 0) || (arr[i] == 1 && count % 2 == 1)){
                if(i + k > n) return -1;
                s.insert(i);
                count++;
                b++;
            }
        }

        return b;
    }
};