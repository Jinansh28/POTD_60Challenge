#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int f = 0;
        for(int i : arr) if(i == 1) f++;
        if(f == 0) return -1;
        
        int a = 0;
        for(int i = 0 ; i < f ; i++) if(arr[i] == 1) a++;
        int swap = f - a;
        
        int j = 0;
        for(int i = f ; i < n ; i++){
            if(arr[j] == 1) a--;
            j++;
            if(arr[i] == 1) a++;
            swap = min(swap, f-a);
        }
        return swap;
    }
};