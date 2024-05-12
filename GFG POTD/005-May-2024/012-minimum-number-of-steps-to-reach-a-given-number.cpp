// https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    // TC : O(tar)
    // SC : O(1)
    int minSteps(int tar) {
        int steps = 0;
        int sum   = 0;
        while((sum < tar) || (tar - sum) % 2 != 0) {
            steps ++;
            sum += steps;
        }
        return steps;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends