// https://www.geeksforgeeks.org/problems/toeplitz-matrix/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// TC : O(M*N)
// SC : O(M*N)
bool approach_1(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    
    unordered_map<int, vector<int>> mpp;
    
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            mpp[i - j].push_back(mat[i][j]);
        }
    }
    
    for (auto& it : mpp) {
        vector<int> vec = it.second;
        for (int i = 1; i < vec.size(); i ++) {
            if (vec[i] != vec[i - 1])
                return false;
        }
    }
    
    return true;
}

// TC : O(M*N)
// SC : O(1)
bool approach_2(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    
    for (int row = 0; row + 1 < m; row ++) {
        for (int col = 0; col + 1 < n; col ++) {
            if (mat[row][col] != mat[row + 1][col + 1]) {
                return false; 
            }
        }
    }
    
    return true;
}

bool isToeplitz(vector<vector<int>>& mat) {
    // return approach_1(mat);
    
    return approach_2(mat);
}