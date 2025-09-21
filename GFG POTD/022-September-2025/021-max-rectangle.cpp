// https://www.geeksforgeeks.org/problems/max-rectangle/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int m, n;

    // TC : O(N)
    // SC : O(N)    
    vector<int> getPse(vector<int> &arr) {
        vector<int> result(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)    
    vector<int> getNse(vector<int> &arr) {
        vector<int> result(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    int getMaxAreaRow(vector<int> &row) {
        vector<int> nse = getNse(row);
        vector<int> pse = getPse(row);
        
        int maxAreaRow = 0;
        for (int i = 0; i < n; i ++) {
            int width  = (nse[i] - pse[i] - 1);
            int height = row[i];
            maxAreaRow = max(maxAreaRow, (height * width));
        }
        return maxAreaRow;
    }
  public:
    // TC : O(M * N)
    // SC : O(N)
    int maxArea(vector<vector<int>> &mat) {
        m = mat.size(), n = mat[0].size();
        
        int maxArea = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i > 0 && mat[i][j] != 0) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
            maxArea = max(maxArea, getMaxAreaRow(mat[i]));
        }
        return maxArea;
    }
};