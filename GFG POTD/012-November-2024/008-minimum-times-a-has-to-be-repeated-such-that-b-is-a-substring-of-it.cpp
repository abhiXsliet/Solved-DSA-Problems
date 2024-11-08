// https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(M * M) Where M = s1.length() & N = s2.length()
    // SC : O(M + N)
    int brute(string& s1, string& s2) {
        int repeatCnt = 1;
        string originalStr = s1;
        while (s1.find(s2) == string::npos) {
            repeatCnt++;
            s1 += originalStr;
            if (s1.length() > s2.length() + 2 * originalStr.length()) {
                return -1;
            }
        }
        return repeatCnt;
    }
  public:
    int minRepeats(string& s1, string& s2) {
        return brute(s1, s2);
        
        // return optimal(s1, s2); // KMP -> Pending ??
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends