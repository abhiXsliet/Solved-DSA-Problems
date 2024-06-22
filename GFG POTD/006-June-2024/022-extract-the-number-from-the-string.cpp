// https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(N) N = Length of the Sentence
    // SC : O(M) M = Max Length of Individual words of sentence 
    long long ExtractNumber(string sentence) {
        stringstream ss(sentence);
        string word;
        long long maxStr = -1;
        while(getline(ss, word, ' ')) {
            long long ans = 0;
            for (char& ch : word) {
                if (ch >= '0' && ch < '9') {
                    ans = ans * 10 + (ch - '0');
                } else if (ch == '9') {
                    ans = 0;
                    break;
                }
            }
            if (ans > 0) 
                maxStr = max(ans, maxStr);
        }
        return maxStr;
    }
};


//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends