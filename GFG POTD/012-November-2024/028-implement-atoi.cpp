// https://www.geeksforgeeks.org/problems/implement-atoi/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int myAtoi(char *s) {
        string str = s;
        int n = str.length();
        
        long long result = 0;
        bool isNegative  = 0;
        bool hasDigits   = 0;
        
        for (int i = 0; i < n; i ++) {
            if (str[i] == ' ') 
                continue;
            if ((str[i] == '-' || str[i] == '+') && result == 0) {
                isNegative = (str[i] == '-');
                continue;   
            }
            
            if (str[i] >= '0' && str[i] <= '9') {
                result    = result * 10 + (str[i] - '0');
                hasDigits = true;
            } else break;
        }
        
        if (!hasDigits) return 0;

        if (isNegative) result = -result;

        if (result > INT_MAX) {
            return INT_MAX;
        } else if (result < INT_MIN) {
            return INT_MIN;
        }
        
        return (int)result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends