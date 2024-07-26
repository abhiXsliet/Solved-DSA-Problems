// https://www.geeksforgeeks.org/problems/k-pangrams0909/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    bool kPangram(string str, int k) {
        int n = str.length();
        
        vector<int> charFreq(26, 0);
        int charCnt = 0;
        for (int i = 0; i < n; i ++) {
            if (str[i] != ' ') {
                char ch = str[i];
                int idx = ch - 'a';
                charFreq[idx] ++;
                charCnt ++;
            }
        }
        
        if (charCnt < 26) return false;
        
        int charNeedToChange = 0;
        for (int i = 0; i < 26; i ++) {
            if (charFreq[i] == 0) {
                charNeedToChange ++;
            }
        }
        
        return charNeedToChange <= k;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends