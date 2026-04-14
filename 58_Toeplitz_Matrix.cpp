#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        unordered_map<int,int> ma;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(ma.find(j-i) == ma.end()) ma[j-i] = mat[i][j];
                else if(ma[j-i] != mat[i][j]) return false;
            }
        }
        return true;
    }
};