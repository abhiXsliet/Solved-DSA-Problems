// https://www.geeksforgeeks.org/problems/remove-k-digits/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    string removeKdig(string S, int k) {
        int n = S.length();
        if (k >= n) return "0";
        
        stack<char> stk;
        
        for (char digit : S) {
            while (!stk.empty() && k > 0 && stk.top() > digit) {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }
        
        while (k > 0) {
            stk.pop();
            k--;
        }
        
        string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        
        reverse(begin(result), end(result));
        
        int len = result.length();
        int startIndex = len;
        
        for (int  i = 0; i < len; i++) {
            if (result[i] != '0') {
                startIndex = i;
                break;
            }
        }
        
        return (startIndex == len ) ? "0" : result.substr(startIndex);
    }
};