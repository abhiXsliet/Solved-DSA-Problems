// https://www.geeksforgeeks.org/problems/house-robber-ii/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int>& arr, int i, int limit, vector<vector<int>> &dp) {
        if (i < limit) return 0;
        
        if (dp[i][limit] != -1) 
            return dp[i][limit];
        
        int op1 = arr[i] + solve(arr, i - 2, limit, dp);
        int op2 = solve(arr, i - 1, limit, dp);
        
        return dp[i][limit] = max(op1, op2);
    }
    
    // TC : O(N)
    // SC : O(N)
    int top_down(vector<int> &arr) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return max(solve(arr, n - 1, 1, dp), solve(arr, n - 2, 0, dp));
    }

    // TC : O(N)
    // SC : O(N)
    int bottom_up(vector<int> &arr) {
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = arr[0];  // considering till 1st house from n - 2
        dp[1][1] = arr[1];  // considering till 2nd house from n - 1 (skip 1st house)
        
        for (int i = 1; i < n; i ++) {
            for (int limit = 0; limit <= 1; limit ++) {
                int op1 = arr[i] + ((i >= 2) ? dp[i - 2][limit] : 0);
                int op2 = dp[i - 1][limit];
                dp[i][limit] = max(op1, op2);
            }
        }
        return max(dp[n - 1][1], dp[n - 2][0]);
    }
    
    // TC : O(N)
    // SC : O(1)
    int space_optimized(vector<int> &arr) {
        auto calc = [&](int start, int end) {
            int prev1 = 0, prev2 = 0;
            for (int i = start; i <= end; i ++) {
                int take    = arr[i] + prev2;
                int notTake = prev1;
                
                int curr = max(take, notTake);
                
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        };
        return max(calc(1, n - 1), calc(0, n - 2));
    }
  public:
    int maxValue(vector<int>& arr) {
        n = arr.size();
        
        // return top_down(arr);
        // return bottom_up(arr);
        return space_optimized(arr);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends