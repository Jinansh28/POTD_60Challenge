#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    bool isValid(vector<int> &arr, int k, int mid){
        int a = 0, b = 1;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] > mid) return false;
            if (a + arr[i] > mid){
                b++;
                a = arr[i];
            } else a += arr[i];
        }
        if(b <= k) return true;
        return false;
    }
    
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        
        int end = 0, st = 0, ans = 0;
        for(int i : arr) {
            st = max(st, i);
            end += i;
        }
        
        if(k == 1) return end;
        
        while(st <= end){
            int mid = st + (end - st)/2;
            if(isValid(arr, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return ans;
    }
};