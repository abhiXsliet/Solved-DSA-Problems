// https://practice.geeksforgeeks.org/problems/c-matrix-rotation-by-180-degree0745/1



//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    void transpose_matrix(vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
    }
    
    void reverse_matrix(vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n; i++) {
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
    
    void solve_clockwise(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        transpose_matrix(matrix, n);
        reverse_matrix(matrix, n);
        
        transpose_matrix(matrix, n);
        reverse_matrix(matrix, n);
    }
    
    void solve_anti_clockwise(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        reverse_matrix(matrix, n);
        transpose_matrix(matrix, n);
        
        reverse_matrix(matrix, n);
        transpose_matrix(matrix, n);
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // solve_clockwise(matrix);
        
        solve_anti_clockwise(matrix);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.rotate(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends