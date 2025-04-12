// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int m, n;
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void bfs(vector<vector<int>> &image, vector<vector<int>> &visited, int sr, int sc, int newColor, int val) {
        image[sr][sc] = newColor;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            image[i][j] = newColor;
            
            for (auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && image[i_][j_] == val) {
                    q.push({i_, j_});
                    visited[i_][j_] = true;
                }
            }
        }
    }
    
    void dfs(vector<vector<int>> &image, vector<vector<int>> &visited, int sr, int sc, int newColor, int val) {
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        for (auto &dir : directions) {
            int newR = sr + dir[0];
            int newC = sc + dir[1];
            
            if (newR >= 0 && newR < m && newC >= 0 && newC < n && image[newR][newC] == val && !visited[newR][newC])
                dfs(image, visited, newR, newC, newColor, val);
        }
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    vector<vector<int>> approach_1(vector<vector<int>> &image, int sr, int sc, int newColor) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int val = image[sr][sc];
        dfs(image, visited, sr, sc, newColor, val);
        return image;
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    vector<vector<int>> approach_2(vector<vector<int>> &image, int sr, int sc, int newColor) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int val = image[sr][sc];
        bfs(image, visited, sr, sc, newColor, val);
        return image;
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size(), n = image[0].size();
        
        // return approach_1(image, sr, sc, newColor);
        return approach_2(image, sr, sc, newColor);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends