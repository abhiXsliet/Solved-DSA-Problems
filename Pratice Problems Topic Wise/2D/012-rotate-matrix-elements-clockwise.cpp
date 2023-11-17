// https://practice.geeksforgeeks.org/problems/rotate-matrix-elements-clockwise2336/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        int n = Mat.size();
        int m = Mat[0].size();
        
        int stRow = 0;
        int enRow = n - 1;
        int stCol = 0;
        int enCol = m - 1;
        
        while (stRow < enRow && stCol < enCol) {
            
            int temp = Mat[stRow][enCol];
            
            // first row
            for (int i = enCol; i > stCol; i--) {
                Mat[stRow][i] = Mat[stRow][i-1]; 
            }
            stRow++;
            
            // first col
            for (int i = stRow; i <= enRow; i++) {
                Mat[i-1][stCol] = Mat[i][stCol];
            }
            stCol++;
            
            if (stRow <= enRow) {
                // fill last row
                for (int i = stCol; i <= enCol; i++) {
                    Mat[enRow][i-1] = Mat[enRow][i];
                }
                enRow--;
            }
            
            if (stCol <= enCol) {
                // fill last col
                for (int i = enRow; i >= stRow; i--) {
                    Mat[i+1][enCol] = Mat[i][enCol];
                }
            }
            
            Mat[stRow][enCol] = temp;
            
            enCol--;
        }
        return Mat;
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
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends