// https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1



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
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // hour glass directions
        vector<pair<int, int>> directions {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}};
        int ans = -1;
        for (int i = 1; i < n - 1; i ++) {
            for (int j = 1; j < m - 1; j ++) {
                int curr = mat[i][j];
                for (auto& d : directions) {
                    curr += mat[i + d.first][j + d.second];
                }
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends