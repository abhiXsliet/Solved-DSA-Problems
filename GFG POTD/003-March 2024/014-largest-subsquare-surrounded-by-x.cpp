// https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int largestSubsquare(int n, vector<vector<char>>& a) {
        vector<vector<int>> hor(n, vector<int>(n, 0));
        vector<vector<int>> ver(n, vector<int>(n, 0));

        // Initialize horizontal and vertical arrays
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j] == 'X') {
                    hor[i][j] = (j==0)? 1: hor[i][j-1] + 1;
                    ver[i][j] = (i==0)? 1: ver[i-1][j] + 1;
                }
            }
        }

        // Start from the largest possible square matrix and one by one check for each cell
        // rightmost bottom of all possible square sub-matrix.
        int max_size = 0;
        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                int small = min(hor[i][j], ver[i][j]);
                while (small > max_size) {
                    if (ver[i][j-small+1] >= small && hor[i-small+1][j] >= small) {
                        max_size = small;
                    }
                    small--;
                }
            }
        }

        return max_size;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends