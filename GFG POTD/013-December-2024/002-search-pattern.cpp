// https://www.geeksforgeeks.org/problems/search-pattern0205/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    vector<int> getLps(string& pat) {
        int n = pat.length();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i ++) {
            int j = lps[i - 1];
            
            while (j > 0 && pat[i] != pat[j]) {
                j = lps[j - 1];
            }
            
            if (pat[i] == pat[j]) j ++;
            lps[i] = j;
        }
        return lps;
    }
  public:
    // TC : O(N + M) Where N = pattern length and M = text length
    // SC : O(N) 
    vector<int> search(string& pat, string& txt) {
        vector<int> prefix = getLps(pat);
        vector<int> result;
        int i = 0, j = 0;
        while (i < txt.size()) {
            if (txt[i] == pat[j]) {
                i++, j++;
            } else {
                if (j != 0) {
                    j = prefix[j - 1];
                } else {
                    i ++;
                }
            }
            
            if (j == pat.size()) {
                result.push_back(i - j);
                j = prefix[j - 1];
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends