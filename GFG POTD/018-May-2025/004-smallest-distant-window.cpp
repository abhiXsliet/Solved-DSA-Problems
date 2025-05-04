// https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        int n = str.length();
        unordered_map<char, int> mpp;
        for (char &ch : str) {
            mpp[ch] ++;
        }
        
        int k = mpp.size(); // window size

        mpp.clear();
        int i = 0, j = 0, ans = INT_MAX;
        while (j < n) {
            mpp[str[j]] ++;
            while (mpp.size() == k) {
                ans = min(ans, j - i + 1);
                mpp[str[i]] --;
                if (!mpp[str[i]]) mpp.erase(str[i]);
                i ++;
            }
            j ++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends