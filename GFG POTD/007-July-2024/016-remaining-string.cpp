// https://www.geeksforgeeks.org/problems/remaining-string3515/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    string printString(string s, char ch, int count) {
        string ans;
        int cnt = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (cnt >= count)
                ans += s[i];
            if (s[i] == ch) 
                cnt += 1;
        }
        return ans;
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
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends