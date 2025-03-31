// https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        int n = s.length();
        vector<int> lastOcc(26, -1);
        for (int i = 0; i < n; i ++) {
            lastOcc[s[i] - 'a'] = i;
        }
        
        int cntSubstr = 0;
        
        int i = 0;
        while (i < n) {
            cntSubstr += 1;
            int len = lastOcc[s[i] - 'a'] - i + 1;
            int newI = i + 1;
            // try to elongate substr-len a/c to last occurances of each char of substring
            for (int j = i + 1; j < n && j < i + len; j ++) {
                len = max(len, lastOcc[s[j] - 'a'] - i + 1);
                newI = j + 1;
            }
            i = newI;
        }
        
        return cntSubstr;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends