// https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(M*N)
    // SC : O(1)
    vector<int> way_1(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int startR = 0;
        int startC = 0;
        int endR   = m - 1;
        int endC   = n - 1;
        int total  = m * n;
        int count  = 0;
        
        vector<int> result;
        while (count < total) {
            for (int j = startC; count < total && j <= endC; j ++) {
                result.push_back(mat[startR][j]);
                count ++;
            }
            startR ++;
            
            for (int i = startR; count < total && i <= endR; i ++) {
                result.push_back(mat[i][endC]);
                count ++;
            }
            endC --;
            
            for (int j = endC; count < total && j >= startC; j --) {
                result.push_back(mat[endR][j]);
                count ++;
            }
            endR --;
            
            for (int i = endR; count < total && i >= startR; i --) {
                result.push_back(mat[i][startC]);
                count ++;
            }
            startC ++;
        }
        return result;
    }
    
    // TC : O(M*N)
    // SC : O(1)
    vector<int> way_2(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int startR = 0;
        int startC = 0;
        int endR   = m - 1;
        int endC   = n - 1;
        int total  = m * n;
        
        vector<int> result;
        while (startR <= endR && startC <= endC) {
            for (int j = startC; j <= endC; j ++) {
                result.push_back(mat[startR][j]);
            }
            startR ++;
            
            for (int i = startR; i <= endR; i ++) {
                result.push_back(mat[i][endC]);
            }
            endC --;
            
            if (startR <= endR) {
                for (int j = endC; j >= startC; j --) {
                    result.push_back(mat[endR][j]);
                }
                endR --;
            }
            
            if (startC <= endC) {
                for (int i = endR; i >= startR; i --) {
                    result.push_back(mat[i][startC]);
                }
                startC ++;
            }
        }
        return result;
    }
  public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        // return way_1(mat);
        
        return way_2(mat);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends