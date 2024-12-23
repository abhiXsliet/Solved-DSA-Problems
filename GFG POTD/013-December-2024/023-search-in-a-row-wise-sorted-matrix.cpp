// https://www.geeksforgeeks.org/problems/search-in-a-row-wise-sorted-matrix/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution { 
  private:
    // TC : O(log(N))
    // SC : O(1)
    bool binarySearchOnEveryRow(vector<vector<int>> &mat, int &r, int &tar) {
        int low = 0, high = mat[r].size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mat[r][mid] == tar) 
                return true;
            else if (mat[r][mid] > tar) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return false;
    }
  public:
    // TC : O(M*log(N))
    // SC : O(1)
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i ++) {
            bool ans = binarySearchOnEveryRow(mat, i, x);
            if (ans) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends