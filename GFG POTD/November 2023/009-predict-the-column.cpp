// https://www.geeksforgeeks.org/problems/predict-the-column/1


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    // TC = O(N*N)
    // SC = O(1)
    int solve_approach_1(vector<vector<int>>& arr, int n) {
        int minIdx = -1;
        int maxi   = 0;
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j][i] == 0) cnt++;
            }
            if (maxi < cnt) {
                minIdx = i;
                maxi = cnt;
            }
        }
        return minIdx;
    }
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
      M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        
        return solve_approach_1(arr, N);
    }
};

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends