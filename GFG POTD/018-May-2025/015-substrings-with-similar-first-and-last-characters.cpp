// https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(string &s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int len = 1; len <= n - i; len ++) {
                string newS = s.substr(i, len);
                if (newS[0] == newS.back()) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(string &s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int ans = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (freq[s[i] - 'a']) {
                ans += (freq[s[i] - 'a']);
            } 
            freq[s[i] - 'a'] ++;
        }
        return ans + n;
    }
  public:
    int countSubstring(string &s) {
        // return brute(s);
        return optimal(s);
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

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends