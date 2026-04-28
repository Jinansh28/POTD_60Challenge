#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int maxlen = 0, n = s.length();
        for(char c = 'A' ; c <= 'Z' ; c++){
            int i = 0, j = 0;
            int non = 0;
            while(j < n){
                if(s[j] != c) non++;
                
                while(i <= j && non > k){
                    if(s[i] != c) non--;
                    i++;
                }
                maxlen = max(maxlen, j-i+1);
                j++;
            }
        }
        return maxlen;
    }
};