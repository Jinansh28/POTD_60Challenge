#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        unordered_set<int> se;
        for(int i = 0 ; i < s.length() ; i++){
            if(se.find(s[i]) != se.end()) se.erase(s[i]);
            else se.insert(s[i]);
        }
        
        return se.size() <= 1;
    }
};