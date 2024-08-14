// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    unordered_map<string, int> mpp;
    
    // TC : O(M * N)
    // SC : O(M * N)
    int mem(string& s1, string& s2, int i, int j, int maxL) {
        if (i >= s1.length() || j >= s2.length())
            return maxL;
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(maxL);
        if(mpp.count(key)) return mpp[key];
        
        int same = 0;
        if (s1[i] == s2[j]) {
            same = mem(s1, s2, i + 1, j + 1, maxL + 1);
        } 
        
        int x = mem(s1, s2, i + 1, j, 0);
        int y = mem(s1, s2, i, j + 1, 0);
        
        return mpp[key] = max(same, max(x, y));
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int tab(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int maxL = 0;
            
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }
                
                maxL = max(maxL, dp[i][j]);
            }
        }
        
        return maxL;
    }
  public:
    int longestCommonSubstr(string str1, string str2) {
        // mpp.clear();
        // return mem(str1, str2, 0, 0, 0);
        
        return tab(str1, str2); // prefix which has longest common suffix
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends