// https://www.geeksforgeeks.org/problems/word-break1352/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    bool solve(string &s, set<string> &st, int idx, vector<int>& dp) {
        if (idx >= n) return true;
        
        if (dp[idx] != -1) return dp[idx];
        
        string str;
        for (int i = idx; i < n; i ++) {
            str += s[i];
            if (st.count(str)) {
                if (solve(s, st, i + 1, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }
  public:
    // TC : O(N*M)
    // SC : O(N)
    bool wordBreak(string &s, vector<string> &dictionary) {
        n = s.length();
        
        set<string> st(begin(dictionary), end(dictionary));
        vector<int> dp(n + 1, -1);
        return solve(s, st, 0, dp);
    }
};

//{ Driver Code Starts.
vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends