// https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(N*M)
    // SC : O(1)
    int minRow(int n, int m, vector<vector<int>> a) {
        int ans = INT_MAX;
        int row = 0;
        for (int i = 0; i < n; i++) {
            int cntOnes = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    cntOnes ++;
                }
            }
            if (ans > cntOnes) {
                ans = cntOnes;
                row = i;
            }
        }
        return row + 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends