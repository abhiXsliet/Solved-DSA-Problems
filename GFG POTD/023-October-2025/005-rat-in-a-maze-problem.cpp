// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/




#include <bits/stdc++.h>
using namespace std;


// User function template for C++
class Solution {
  private:
    vector<vector<int>> directions {{-1, 0, 1}, {1, 0, 2}, {0, -1, 3}, {0, 1, 4}};
    
    bool isPossibleToMove(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;    
    }
    
    // TC : O(3^(N*N)) since rat has only 3-possible ways to go(i.e., if rat coming from top then can move to down, left, right, can't go up since it is already coming from upward)
    // SC : O(N*N) Recursive Depth
    void solve(int i, int j, int n, vector<string>& result, string &path, vector<vector<int>>& mat, vector<vector<int>>& vis) {
        if (!isPossibleToMove(i, j, n) || vis[i][j] || !mat[i][j])
            return;
            
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }
        
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            char ch = (dir[2] == 1) ? 'U' : (dir[2] == 2) ? 'D' : (dir[2] == 3) ? 'L' : 'R';
            
            path.push_back(ch);
            vis[i][j] = 1;
            
            solve(i_, j_, n, result, path, mat, vis);
            
            path.pop_back();
            vis[i][j] = 0;
        }
    }
  public:
    // TC : O(3^(N^2))
    // SC : O(N)
    vector<string> ratInMaze(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> result;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path;
        solve(0, 0, n, result, path, mat, visited);
        sort(begin(result), end(result));
        return result;
    }
};