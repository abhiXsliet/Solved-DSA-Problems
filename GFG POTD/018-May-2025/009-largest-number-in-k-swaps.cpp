// https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int getMaxIdxFromI(string &s, int index) {
        int n = s.length();
        int idx = -1, val = INT_MIN;
        for (int i = index; i < n; i ++) {
            if (s[i] - '0' >= val) {
                val = s[i] - '0';
                idx = i;
            }
        }
        return idx;
    }
  public:
    // Function to find the largest number after k swaps.
    // TC : O((N^2)^K)
    // SC : O(1)
    string findMaximumNum(string& s, int k) {
        int n = s.length();
        int i = 0;
        while (i < n && k) {
            int maxIdx = getMaxIdxFromI(s, i);
            if (s[maxIdx] != s[i]) {
                swap(s[i], s[maxIdx]);
                k --;
                if (k == 0) break;
            }
            i ++;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends