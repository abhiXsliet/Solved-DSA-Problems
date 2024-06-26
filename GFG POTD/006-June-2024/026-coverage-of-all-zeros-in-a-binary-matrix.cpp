// https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(M*N)
    // SC : O(1)
    int findCoverage(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    for (auto& dir : directions) {
                        int i_ = dir[0] + i;
                        int j_ = dir[1] + j;
                        
                        if (i_ < m && i_ >= 0 && j_ < n && j_ >= 0 && matrix[i_][j_] == 1) {
                            ans += 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends