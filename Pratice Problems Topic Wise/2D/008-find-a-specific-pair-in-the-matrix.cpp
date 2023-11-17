// https://www.codingninjas.com/studio/problems/find-a-specific-pair-in-the-matrix_1115467


#include <bits/stdc++.h> 
using namespace std;


// TC = O(N * N)
// SC = O(N * N)
int solve_optimal_1(vector<vector<int>>& mat, int n) {
	// step-1 : create a matrix with maximum value (matMax)
	vector<vector<int>> matMax(n, vector<int>(n, INT_MIN));
	
	// step-2 : fill the matMax with maximum values
	
	matMax[n - 1][n - 1] = mat[n - 1][n - 1];
	
	// fill the last row of matMax
	for (int j = n - 2; j >= 0; j--) {
		matMax[n - 1][j] = max({mat[n - 1][j], matMax[n - 1][j], matMax[n - 1][j + 1]});
	}
	
	// fill the last col of matMax
	for (int i = n - 2; i >= 0; i--) {
		matMax[i][n - 1] = max({mat[i][n - 1], matMax[i][n - 1], matMax[i + 1][n - 1]});
	}
	
	// fill the remaining row's and col's of matMax
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			matMax[i][j] = max({mat[i][j], matMax[i + 1][j], matMax[i][j + 1]});
		}
	}
	
	// Initialize ans
	int ans = INT_MIN;
	// step-3 : find the maximum ans from the matMax and matrix
	
	// c > a && d > b => c = a + 1, d = b + 1 starting
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			ans = max(ans, (matMax[i + 1][j + 1] - mat[i][j]));
		}
	}
	
	return ans;
}

// TC = O(N * N)
// SC = O(N)
int solve_optimal_2(vector<vector<int>>&mat, int n) {
	vector<int> vec1(n, INT_MIN);
	vector<int> vec2(n, INT_MIN);
	
	// fill the vec1 first
	vec1[n - 1] = mat[n - 1][n - 1];
	
	for (int j = n - 2; j >= 0; j--) {
		vec1[j] = max(mat[n - 1][j], vec1[j + 1]);
	}
	
	int ans = INT_MIN;
	
	// fill vec2 and find the maximum of ans 
	for (int i = n - 2; i >= 0; i--) {
		// fill vec2
		vec2[n - 1] = max(mat[i][n - 1], vec1[n - 1]);
		
		for (int j = n - 2; j >= 0; j--) {
			// to get max ans -> c = i + 1 && d = j + 1
			ans = max( ans, (vec1[j + 1] - mat[i][j]) );
			
			vec2[j] = max({mat[i][j], vec1[j], vec2[j + 1]});
		}
		vec1 = vec2;
	}
	return ans;
}
int findMaxValue(vector<vector<int>>& mat, int n) {
	// return solve_optimal_1(mat, n);

	return solve_optimal_2(mat, n);
}