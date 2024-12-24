// https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(M + N)
    // SC : O(1)
    bool approach_1(vector<vector<int>>& mat, int x) {
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (mat[row][col] == x)
                return true;
            else if (mat[row][col] > x)
                col --;
            else 
                row ++;
        }
        return false;
    }
    
    // TC : O(log(M*N))
    // SC : O(1)
    bool approach_2(vector<vector<int>>& mat, int x) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m*n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            if (mat[row][col] == x) 
                return true;
            else if (mat[row][col] > x) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return false;
    }
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // return approach_1(mat, x);
        return approach_2(mat, x);
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
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends