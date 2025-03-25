// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for (int k = i; k < j; k ++) {
            int cost = arr[i - 1] * arr[k] * arr[j] + 
                        solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
            ans = min(ans, cost);
        }
        
        return dp[i][j] = ans;
    }
    
    // TC : O(N * N)
    // SC : O(N * N)
    int top_down(vector<int>& arr) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, 1, n - 1, dp);    
    }

    // TC : O(N * N)
    // SC : O(N * N)
    int bottom_up(vector<int>& arr) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 1; i --) {
            for (int j = i + 1; j < n; j ++) {
                int ans = INT_MAX;
                for (int k = i; k < j; k ++) {
                    int cost = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    ans = min(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n - 1];    
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        n = arr.size();
        
        // return top_down(arr);
        return bottom_up(arr);
        // return space_optimized(arr);    // Pending?
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}
// } Driver Code Ends