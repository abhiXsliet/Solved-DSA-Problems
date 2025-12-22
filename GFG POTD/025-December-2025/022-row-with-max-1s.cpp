// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1/




#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public: 
    // TC : O(M + N) Where M = No. of Rows and N = No. of Cols
    // SC : O(1)
    int rowWithMax1s(vector<vector<int>> &arr) {
        int m = arr.size(), n = arr[0].size();
        
        int i = 0, j = n - 1;
        int maxOneRow = -1;
        
        while (i < m && j >= 0) {
            if (arr[i][j]) {
                j --;
                maxOneRow = max(maxOneRow, i);
            } else i ++;
        }
        return maxOneRow;
    }
};