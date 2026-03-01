#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int,int> m;
        
        int b = 0, a = 0;
        for(int i : arr){
            b = b ^ i;
            if(b == k) a++;
            if(m.find(k^b) != m.end()) a += m[k^b];
            m[b]++;
        }
        
        return a;
        
    }
};