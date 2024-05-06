// https://leetcode.com/problems/add-binary/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N + M) Where N, M are length of string a and b respectively
    // SC : O(1)
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        string ans;
        int carr = 0;
        
        while (i >= 0 || j >= 0) {
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            
            int sum = x + y + carr;
            
            if (sum % 2) ans += '1';
            else ans += '0';
            
            if (sum > 1) carr = 1;
            else carr = 0;

            i --, j --;
        }
        if (carr > 0) ans += '1';
        reverse(begin(ans), end(ans));
        return ans;
    }
};