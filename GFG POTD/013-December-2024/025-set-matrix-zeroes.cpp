// https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(M * N * log(M * N))
    // SC : O(M * N)
    void brute(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        set<pair<int, int>> st;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) {
                    st.insert({i, j});
                }
            }
        }
        for (auto &it : st) {
            int r = it.first;
            int c = it.second;
            for (int j = 0; j < n; j ++) {
                mat[r][j] = 0;   
            }
            for (int i = 0; i < m; i ++) {
                mat[i][c] = 0;
            }
        }
    }
    
    // TC : O(M * N)
    // SC : O(1)
    void optimal(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        bool isFirstRow = 0, isFirstCol = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!mat[i][j]) {
                    if (i == 0 && j == 0) {
                        isFirstRow = 1;
                        isFirstCol = 1;
                    } else if (i == 0) {
                        isFirstRow = 1;
                    } else if (j == 0) {
                        isFirstCol = 1;
                    } else {
                        mat[i][0] = 0;  // store which row index marked to be zero
                        mat[0][j] = 0;  // store which col. index marked to be zero 
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (!mat[0][j] || !mat[i][0] || i == 0 && isFirstRow || j == 0 && isFirstCol) {
                    mat[i][j] = 0;
                }
            }
        }
    }
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // brute(mat);
        
        optimal(mat);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends