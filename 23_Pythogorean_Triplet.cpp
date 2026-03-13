#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_set<int> s;
        
        for(int i = 0 ; i < n ; i++) s.insert(arr[i] * arr[i]);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int a = (arr[i] * arr[i]) + (arr[j] * arr[j]);
                if(s.find(a) != s.end()) return true;
            }
        }
        return false;
    }
};