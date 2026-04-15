#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string URLify(string &s) {
        // code here
        string a = "";
        for(char c : s){
            if(c == ' ') a += "%20";
            else a += c;
        }
        return a;
    }
};62