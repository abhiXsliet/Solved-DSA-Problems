// https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(string &s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        for (int i = 1; i < n; i ++) {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) j ++;
            lps[i] = j;
        }
        
        return lps[n - 1];
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_2(string &s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int result = 0, len = 0, j = 1;
        while (j < n) {
            if (s[len] == s[j]) {
                len ++;
                lps[j] = len;
                j ++;
            } else {
                if (len != 0) {    
                    len = lps[len - 1];
                } else {
                    lps[j] = 0;
                    j ++;
                }
            }
        }
        return lps[n - 1];
    }
  public:
    int longestPrefixSuffix(string &s) {
        // return approach_1(s);   
        return approach_2(s);   // best : no inner while loop
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

        cout << ob.longestPrefixSuffix(str) << "\n";
    }

    return 0;
}
// } Driver Code Ends