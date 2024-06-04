// https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    string binaryNextNumber(string s) {
        int n = s.length();
        bool change = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                s[i] = '1';
                change = 0;
                break;
            } else {
                s[i] = '0';
            }
        }
        if (change) {
            s = '1' + s;
        }
        int idx = s.find_first_not_of('0');
        s.erase(s.begin() + 0, s.begin() + idx);
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends