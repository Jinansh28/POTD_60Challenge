#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code her
        int n = arr.size(), i = 0;
        
        vector<int> a;
        
        while(i < n){
            if(a.size() == 0){
                a.push_back(arr[i]);
                i++;
                continue;
            }
            int m = a.size()-1;
            
            while(i < n && ((arr[i] > 0 && a[m] < 0) || (arr[i] < 0 && a[m] > 0)) && abs(a[m]) > abs(arr[i])){
                i++;
            }
            
            if(i >= n) break;
            
            if((arr[i] > 0 && a[m] < 0) || (arr[i] < 0 && a[m] > 0)){
                if(abs(a[m]) < abs(arr[i])){
                    while(m >= 0 && ((arr[i] > 0 && a[m] < 0) || (arr[i] < 0 && a[m] > 0)) && abs(a[m]) < abs(arr[i])){
                        a.pop_back();
                        m = a.size()-1;
                    }
                    if(m >= 0 && ((arr[i] > 0 && a[m] < 0) || (arr[i] < 0 && a[m] > 0))){
                        if(abs(a[m]) < abs(arr[i])){
                            a.push_back(arr[i]);
                        }
                        else if(abs(a[m]) == abs(arr[i])) a.pop_back();
                    }
                    if(m == -1) a.push_back(arr[i]);
                }
                else a.pop_back();
            }
            else a.push_back(arr[i]);
            i++;
        }
        return a;
    }
};