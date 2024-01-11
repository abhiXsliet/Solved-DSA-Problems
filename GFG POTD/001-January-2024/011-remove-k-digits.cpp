// https://www.geeksforgeeks.org/problems/remove-k-digits/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    string removeKdigits(string S, int k) {
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends