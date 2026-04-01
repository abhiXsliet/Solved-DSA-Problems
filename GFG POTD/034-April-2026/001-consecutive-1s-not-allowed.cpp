// https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int t[45][2];
    
    int func(int len, int last, int n) {
        if (len == n) return 1;
        
        if (t[len][last] != -1) return t[len][last];
        
        int op1 = func(len + 1, 0, n);  // add '0' to last
        
        int op2 = 0;
        if (last != 1) {
            op2 = func(len + 1, 1, n);  // add '1' to last
        }
        
        return t[len][last] = (op1 + op2);
    }
    
    int solve(string str, int n) {
        if (str.length() == n) return 1;
        
        str += '0';
        int op1 = solve(str, n);
        str.pop_back();
        
        int op2 = 0;
        if (!str.empty() && str.back() != '1') {
            str += '1';
            op2 = solve(str, n);
            str.pop_back();
        }
        
        return (op1 + op2);
    }
    
    // TC : O(2^n)
    int brute(int n) {
        int zeros = solve("0", n);
        int ones  = solve("1", n);
        return (zeros + ones);
    }
    
    int optimal(int n) {
        memset(t, -1, sizeof(t));
        // start with '0' and '1' 
        return func(1, 0, n) + func(1, 1, n);
    }
    
    int so(int n) {
        int a = 1;  // start with '0'
        int b = 1;  // start with '1'
        
        for (int i = 2; i <= n; i ++) {
            int new_a = a + b;  // '0' kahi bhi aa sakta hai
            int new_b = a;      // '1' sirf '0' ke baad hi aa sakta hai
            
            a = new_a;
            b = new_b;
        }
        return (a + b);
    }
  public:
    int countStrings(int n) {
        // return brute(n);
        // return optimal(n);
        return so(n);
    }
};