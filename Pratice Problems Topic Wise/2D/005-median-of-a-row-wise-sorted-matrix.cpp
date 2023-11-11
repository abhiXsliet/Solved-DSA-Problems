// https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473


#include <bits/stdc++.h>
using namespace std;

// TC = O(log(m))
int upper_bound (vector<int>& mat, int val, int m) {
    int low  = 0;
    int high = m - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mat[mid] > val) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    
    return low;
}

// TC = O(row * log(col)) -> O(n * log(m)) where n = rows, m = cols
int getNoOfNos(vector<vector<int>>& mat, int n, int m, int val) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += upper_bound(mat[i], val, m);
    }
    return cnt;
}

// TC = O(log(1e9) * nlog(m)) -> TC(BS * upperBound)
int median(vector<vector<int>> &matrix, int R, int C){
    int low  = INT_MAX;
    int high = INT_MIN;
    
    for (int i = 0; i < R; i++) {
        low = min(low, matrix[i][0]);
        
        high = max(high, matrix[i][C-1]);
    }
    
    int median_idx = (R * C) / 2;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // count numbers of no. 
        // nosOfNo is the how many no. is less than or equal to that no. 
        int noOfNos_mid  = getNoOfNos(matrix, R, C, mid);
        
        if (noOfNos_mid <= median_idx) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    
    return low;
}