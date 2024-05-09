// https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// TC : O(1)
// SC : O(1)
class Solution {
  public:
    bool divisorGame(int n) {
        if (n % 2) return 0;
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        bool ans = obj.divisorGame(n);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends