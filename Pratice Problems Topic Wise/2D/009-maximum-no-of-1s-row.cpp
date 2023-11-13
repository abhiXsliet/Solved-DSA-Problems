// https://practice.geeksforgeeks.org/problems/maximum-no-of-1s-row3027/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    // TC = O(N * M)
    // SC = O(1)
    int solve_brute(vector<vector<int>>& mat, int n, int m) {
        int maxi = 0;
        int idx  = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    cnt += 1;
                }
            }
            if (maxi < cnt) {
                maxi = cnt;
                idx  = i;
            }
        }
        return idx;
    }
    
    // TC = O(N * log(M))
    // SC = O(1)
    int solve_optimal_1(vector<vector<int>>& mat, int n, int m) {
        int idx = -1;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int cnt = m - (lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin());
            
            if (cnt > maxi) {
                maxi = cnt;
                idx  = i;
            }
        }
        return idx;
    }
    
    // TC = O(N * log(M))
    // SC = O(1)
    int solve_optimal_2(vector<vector<int>>& mat, int n, int m) {
        int idx = -1;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int cnt = m - (upper_bound(mat[i].begin(), mat[i].end(), 0) - mat[i].begin());
            
            if (cnt > maxi) {
                maxi = cnt;
                idx  = i;
            }
        }
        return idx;
    }
    
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // return solve_brute(Mat, N, M);
            
            // return solve_optimal_1(Mat, N, M);
            
            return solve_optimal_2(Mat, N, M);
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends