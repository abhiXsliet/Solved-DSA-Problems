// https://www.geeksforgeeks.org/problems/search-in-fully-rotated-sorted-2d-matrix/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(log( N * M ))
    // SC : O(1)
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        
        int low = 0, high = n*m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;
            
            if (mat[row][col] == x) return true;
            
            int rLo = low  / m, cLo = low  % m;
            int rHi = high / m, cHi = high % m;
            
            if (mat[rLo][cLo] <= mat[row][col]) {    // left part is sorted : arr[low] <= arr[mid]
      
                if (x < mat[row][col] && x >= mat[rLo][cLo]) {
                    high = mid - 1;
                } else {
                    low  = mid + 1;
                }
                
            } else {    // right part is sorted : arr[mid] <= arr[high]
               
                if (x > mat[row][col] && x <= mat[rHi][cHi]) {
                    low  = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};