// https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
    int max = 1e9;
    
    int rec(int i, int j, vector<vector<int>>& mat, vector<vector<bool>>& vis){
        
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || vis[i][j] == true || mat[i][j] == 0 || !isValid(i, j, mat)) return max;
        
        if(j == mat[0].size() - 1)  return 1; 
        
        vis[i][j] = true;
        
        int up = 1 + rec(i - 1, j, mat, vis);
        int down = 1 + rec(i + 1, j, mat, vis);
        int right = 1 + rec(i, j + 1, mat, vis);
       
        vis[i][j] = false; // backtracking 
        
        return min({up, down, right});
    }
    
    bool isValid(int i, int j, vector<vector<int>>& mat){
        
        if(i - 1 >= 0 && mat[i - 1][j] == 0) return false;
        if(i + 1 < mat.size() && mat[i + 1][j] == 0) return false;
        if(j + 1 < mat[0].size() && mat[i][j + 1] == 0) return false;
        if(j - 1 >= 0 && mat[i][j - 1] == 0) return false;
        return true;
    }
public:
    int findShortestPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int min = max;
        for(int i = 0; i < n; i++){
            min = std::min(min, rec(i, 0, mat, vis)); // from leftmost to rightmost
        }
        return min == max ? -1 : min;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends