// https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(r*r)
    // SC : O(1)
    int rectanglesInCircle(int r) {
        int result   = 0;
        int diameter = 2*r;
        for (int l = 1; l <= diameter; l ++) {
            for (int w = 1; w <= diameter; w ++) {
                double diagonal = sqrt(l*l + w*w);
                if (diagonal <= diameter) 
                    result ++;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends