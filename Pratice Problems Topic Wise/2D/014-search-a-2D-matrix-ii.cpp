// https://leetcode.com/problems/search-a-2d-matrix-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool binarySearch(vector<int>& arr, int tar, int m) {
        int low  = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == tar) {
                return true;
                break;
            }
            else if (arr[mid] < tar) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return 0;
    }

    // TC = O(N * log(M)) -> searching on every row(n) * binary_search on each row(n)
    // SC = O(1)
    bool solve_better(vector<vector<int>>& mat, int tar) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            if (binarySearch(mat[i], tar, m))
                return true;
        }
        return false;
    }

    // TC = O(N + M)
    // SC = O(1)
    bool optimal(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col - 1 ;
        
        while(rowIndex < row && colIndex >= 0)
        {
            int element = matrix[rowIndex][colIndex];
            
            if(element == target){
                return 1;
            }
            
            if(element < target)
            {
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
        }
        return 0;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return solve_better(matrix, target);

        return optimal(matrix, target);
    }
};