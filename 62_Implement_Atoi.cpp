#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        string a = "";
        int n = s.length(), i = 0;
        while(i < n && (s[i] <= 48 || s[i] > 57 ) && s[i] != '-') i++;
        
        if(i >= n) return 0;
        if(s[i] == '-') {
            a += '-';
            i++;
        }
        
        while(i < n && s[i] == 48) i++;
        if(s[i] > 48 && s[i] <= 57) a += s[i++];
        else return 0;
        while(i < n && s[i] >= 48 && s[i] <= 57) a += s[i++];
        
        long long ans = 0;
        if(a[0] == '-'){
            for(int i = 1 ; i < a.length() ; i++){
                ans *= 10;
                ans -= a[i] - 48;
                if(ans < -2147483648) return -2147483648;
            }
            return ans;
        }
        for(int i = 0 ; i < a.length() ; i++){
            ans *= 10;
            ans += a[i] - 48;
            if(ans > 2147483647) return 2147483647;
        }
        return ans;
    }
};
