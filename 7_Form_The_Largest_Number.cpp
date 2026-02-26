#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     static bool cmp(string a, string b){
        return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        
        vector<string> str;
        
        for(int i : arr){
            str.push_back(to_string(i));
        }
        sort(str.begin(), str.end(), cmp);
        if(str[0] == "0") return "0";
        string s = "";
        for(int i = 0 ; i < str.size() ; i++) s+=str[i];
        
        
        
        return s;
    }
};