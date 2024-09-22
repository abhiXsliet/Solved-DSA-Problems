// https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // TC : O(N)
    // SC : O(N) where N = s.length()
    int lps(string s) {
        int n = s.length();
        vector<int> prefix(n, 0);
        
        for (int i = 1; i < n; i ++) {
            int j = prefix[i - 1];
            
            while (j > 0 && s[j] != s[i])
                j = prefix[j - 1];
            
            if (s[j] == s[i]) j ++;
            prefix[i] = j;
        }
        
        return prefix[n - 1];
    }
};


//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
// } Driver Code Ends