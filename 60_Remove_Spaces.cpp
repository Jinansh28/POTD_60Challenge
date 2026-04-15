#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string a = "";
        for(char c : s) if(c != ' ') a += c;
        return a;
    }
};