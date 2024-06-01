// https://www.geeksforgeeks.org/problems/help-nobita0532/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        for (char& ch : s) {
            mpp[ch] ++;
        }
        
        int x = 0, y = 0;
        for (auto& it : mpp) {
            if (it.second % 2 == 0 && (it.first - '0') % 2 == 0) {
                x ++;
            } else if (it.second % 2 != 0 && (it.first - '0') % 2 != 0) {
                y ++;
            }
        }
        
        if ((x + y) % 2 == 0) {
            return "EVEN";
        }
        return "ODD";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}
// } Driver Code Ends