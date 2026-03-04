#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   int countSquare(vector<vector<int>>& mat, int x) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> vec(r+1, vector<int>(c+1,0));
        int res = 0;
        
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            vec[i+1][j+1] = mat[i][j] + vec[i][j+1] + vec[i+1][j] - vec[i][j];
            for(int k = min(i,j);k>=0;k--)
            if(vec[i+1][j+1] - vec[i-k][j+1] - vec[i+1][j-k] + vec[i-k][j-k] == x)
            res ++;
        }
        
        return res;
    }
};  