// https://leetcode.com/problems/sort-matrix-by-diagonals/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(max(m, n)  + klog(k)) ~= O(klogk) where K = max no. of elements in a diagonal
    // SC : O(k)
    void sortDiag(int r, int c, int m, int n, vector<vector<int>>& grid, bool isLowerDiag) {
        vector<int> diagElements;
        int i = r, j = c;
        while (i < m && j < n) {
            diagElements.push_back(grid[i][j]);
            i ++, j ++;
        }
        if (isLowerDiag) {
            sort(begin(diagElements), end(diagElements));
        } else {
            sort(rbegin(diagElements), rend(diagElements));
        }

        // insert into grid the sorted values
        i = r, j = c;
        while (i < m && j < n) {
            grid[i][j] = diagElements.back();
            diagElements.pop_back();
            i ++, j ++;
        }
    }

    // TC : O(M * N + M*Klog(K)) ~= O(M * N)
    // SC : O(M * N)
    vector<vector<int>> approach_1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                mpp[i - j].push_back(grid[i][j]);
            }
        }
        for (auto& it : mpp) {
            if (it.first >= 0) 
                sort(begin(it.second), end(it.second));
            else 
                sort(rbegin(it.second), rend(it.second));
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                grid[i][j] = mpp[i - j].back();
                mpp[i - j].pop_back();
            }   
        }
        return grid;
    }

    // TC : O( (M + N) * Klog(K) )
    // SC : O(K)
    vector<vector<int>> approach_2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i ++) {
            sortDiag(i, 0, m, n, grid, 1);  
        }
        for (int j = 1; j < n; j ++) {
            sortDiag(0, j, m, n, grid, 0);  
        }
        return grid;
    }
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // return approach_1(grid);     // USING HASH MAP : {int, {int}}
        return approach_2(grid);     // More of SIMULATION
    }
};