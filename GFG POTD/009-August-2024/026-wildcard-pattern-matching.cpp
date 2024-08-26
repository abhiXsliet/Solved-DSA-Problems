// https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int m;
    int n;

    int t[201][201];
    int solve(string& pat, string& str, int i, int j) {
        if (i == m && j == n) return 1;
        if (i >= m && j  < n) return 0;
        if (i < m && j >= n) {
            for (int k = m - 1; k >= i; k --) {
                if (pat[k] != '*')
                   return false; 
            }
            return true;
        }

        if (t[i][j] != -1) return t[i][j];
        
        if (pat[i] == str[j] || pat[i] == '?') {
            return t[i][j] = solve(pat, str, i + 1, j + 1);
        } else if (pat[i] == '*') {
            return t[i][j] = (solve(pat, str, i, j + 1) || solve(pat, str, i + 1, j));
        } 
        
        return t[i][j] = false; // else
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int tab(string& pat, string& str) {
        memset(t, 0, sizeof(t));
        
        t[m][n] = 1;
        
        for (int i = 0; i < m; i ++) {  // pattern is remaining
            bool flag = 1;
            for (int k = m - 1; k >= i; k --) {
                if (pat[k] != '*') {
                    flag = 0;
                    break;
                }
            }
            t[i][n] = flag;
        }

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                
                if (pat[i] == str[j] || pat[i] == '?') {
                    t[i][j] = t[i + 1][j + 1];
                } else if (pat[i] == '*') {
                    t[i][j] = (t[i][j + 1] || t[i + 1][j]);
                } 
                else t[i][j] = false;
            }
        }
        
        return t[0][0];
    }
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        m = pattern.size();
        n = str.size();
        
        // memset(t, -1, sizeof(t));
        // return solve(pattern, str, 0, 0);
        
        return tab(pattern, str);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}
// } Driver Code End