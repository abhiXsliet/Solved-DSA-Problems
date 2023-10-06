// https://leetcode.com/problems/integer-break/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int t[59];
    int solve(int n ){
        
        if(n == 1)
            return 1;
        
        if(t[n] != -1)
            return t[n];
        
        int result = INT_MIN;
      
        for(int i = 1; i<n; i++) {
            int prod = i * max(n-i, solve(n-i));
            
            result = max(result, prod);
        }
        
        return t[n] = result;
        
    }
    
    int integerBreak(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};