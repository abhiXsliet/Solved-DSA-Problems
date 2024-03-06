// https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    #define d 256
    int MOD = 1e9 + 7;
    
    // TC : O(N + M)
    // TC : O(N*M) At Worst
    // SC : O(1)
    vector<int> solve(string& pat, string& txt) {
        int m = pat.length();
        int n = txt.length();
        
        vector<int> result;
        
        int patHash = 0;
        int txtHash = 0;
        
        int h = 1;
        
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % MOD;
        }
        
        // calculate the hash for both pattern and text
        for (int i = 0; i < m; i++) {
            patHash = (d * patHash + pat[i]);
            txtHash = (d * txtHash + txt[i]);
        }
        
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            
            if (j == m) {
                result.push_back(i + 1);
            }
            
            // Calculate hash value for next window of text:
            // Remove leading digit, add trailing digit
            if (i < n - m) {
               
                txtHash = (d * (txtHash - txt[i] * h) + txt[i + m]) % MOD;
                
                if (txtHash < 0) 
                    txtHash += MOD;
            }
        }
        return result;
    }
    public:
    vector <int> search(string pat, string txt) {
        return solve(pat, txt);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends