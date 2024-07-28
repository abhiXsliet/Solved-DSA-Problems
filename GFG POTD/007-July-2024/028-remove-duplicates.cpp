// https://www.geeksforgeeks.org/problems/remove-duplicates3034/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    string removeDups(string str) {
        int n = str.length();
        vector<int> freq(26, 0);
        string result;
        for (int i = 0; i < n; i ++) {
            int idx = str[i] - 'a';
            if (freq[idx] == 0) {
                result += str[i];
                freq[idx] ++;
            }
        }
        return result;
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends