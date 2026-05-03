#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        string s = bitset <64> (N).to_string();
        int n = s.length(), i = 0;
        while(i < n && s[i] == '0') i++;
        s = s.substr(i);
        
        int j = s.length()-1;
        i = 0;
        while(i < j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};