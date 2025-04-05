// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n, m;
    vector<vector<int>> directions {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    
    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 'W';
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] == 'L') {
                        q.push({i_, j_});
                        grid[i_][j_] = 'W';
                    }
                }
            }
        }
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = 'W';
        for (auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] == 'L') {
                dfs(grid, i_, j_);
            }
        }
    }
    
    // TC : O(N * M)
    // SC : O(1)
    int approach_1(vector<vector<char>> &grid) {
        int cntIslands = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 'L') {
                    cntIslands += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return cntIslands;
    }

    // TC : O(N * M)
    // SC : O(1)
    int approach_2(vector<vector<char>> &grid) {
        int cntIslands = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 'L') {
                    cntIslands += 1;
                    bfs(grid, i, j);
                }
            }
        }
        return cntIslands;
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        // return approach_1(grid);
        return approach_2(grid);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends