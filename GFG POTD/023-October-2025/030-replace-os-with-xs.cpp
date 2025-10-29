// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int row, int col, vector<vector<bool>>& vis, 
            vector<vector<char>>& mat, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        int n = mat.size(), m = mat[0].size();
        
        // check all four directions
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i]; 
            int nCol = col + delCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                !vis[nRow][nCol] && mat[nRow][nCol] == 'O') {
                dfs(nRow, nCol, vis, mat, delRow, delCol);
            }
        }
    }

  public:
    void fill(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        // traverse first row and last row
        for (int j = 0; j < m; j++) {
            
            // first row
            if (!vis[0][j] && mat[0][j] == 'O') 
                dfs(0, j, vis, mat, delRow, delCol);
            
            // last row
            if (!vis[n-1][j] && mat[n-1][j] == 'O') 
                dfs(n-1, j, vis, mat, delRow, delCol);
        }
        
        // traverse on the first and last col
        for (int i = 0; i < n; i++) {
            // first col
            if  (!vis[i][0] && mat[i][0] == 'O') 
                dfs(i, 0, vis, mat, delRow, delCol);
            
            // last col    
            if (!vis[i][m-1] && mat[i][m-1] == 'O')
                dfs(i, m-1, vis, mat, delRow, delCol);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};