// https://geeksforgeeks.org/problems/non-repeating-character-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        vector<int> freq(26, 0);
        for (char& ch : s) {
            freq[ch - 'a'] ++;
        }
        for (char& ch : s) { 
            if (freq[ch - 'a'] == 1) {
                return ch;
            }
        }
        return '$';
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends