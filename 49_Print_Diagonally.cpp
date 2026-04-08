#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> a(2*n -1);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                a[i+j].push_back(mat[i][j]);
            }
        }
        
        vector<int> ans;
        for(int i = 0 ; i < a.size(); i++){
            for(int j : a[i]){
                ans.push_back(j);
            }
        }
        return ans;
    }
};