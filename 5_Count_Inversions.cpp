#include<bits/stdc++.h>
using namespace std;    

class Solution {
  public:
    void merge(int st, int end, int mid, vector<int> &arr, int &inv){
        int i = st, j = mid + 1;
        vector<int> temp;
        while(i <= mid && j <= end){
            if(arr[i] > arr[j]){
                temp.push_back(arr[j++]);
                inv += (mid-i+1);
            }
            else temp.push_back(arr[i++]);
        }
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=end) temp.push_back(arr[j++]); 
       
        for(int c = 0 ; c < temp.size(); c++) arr[c+st] = temp[c];
        return;
    }
  
    void mergeSort(vector<int> &arr, int i, int j, int &inv){
        if(i < j){
            int mid = i + (j - i)/2;
            mergeSort(arr, i, mid, inv);
            mergeSort(arr, mid + 1 , j, inv);
            merge(i , j, mid, arr, inv);
        }
    }
    
    int inversionCount(vector<int> &arr) {
        int inv = 0;
        mergeSort(arr, 0, arr.size()-1, inv);
        return inv;
    }
};