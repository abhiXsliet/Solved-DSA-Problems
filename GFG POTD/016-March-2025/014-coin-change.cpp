// https://www.geeksforgeeks.org/problems/coin-change2448/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    
    int n;
    int solve(vector<int> &coins, int i, int sum, vector<vector<int>> &dp) {
        if (i >= n || sum <= 0) {
            return sum == 0;
        }
        
        if (dp[i][sum] != -1) return dp[i][sum];
        
        int take = solve(coins, i, sum - coins[i], dp);
        int notT = solve(coins, i + 1, sum, dp);
        
        return dp[i][sum] = (take + notT);
    }
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int top_down(vector<int> &coins, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(coins, 0, sum, dp);
    }
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int bottom_up(vector<int> &coins, int summ) {
        vector<vector<int>> dp(n + 1, vector<int>(summ + 1, 0));
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int sum = 1; sum <= summ; sum ++) {
                int take = (sum - coins[i] >= 0) ? dp[i][sum - coins[i]] : 0;
                int notT = dp[i + 1][sum];
                dp[i][sum] = (take + notT);
            }
        }
        return dp[0][summ];
    }
    
    // TC : O(N * Sum)
    // SC : O(Sum)
    int space_optimized(vector<int> &coins, int summ) {
        vector<int> curr(summ + 1, 0), prev(summ + 1, 0);
        for (int i = 0; i <= n; i ++) {
            curr[0] = 1;
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int sum = 1; sum <= summ; sum ++) {
                int take = (sum - coins[i] >= 0) ? curr[sum - coins[i]] : 0;
                int notT = prev[sum];
                curr[sum] = (take + notT);
            }
            prev = curr;
        }
        return prev[summ];
    }
  public:
    int count(vector<int>& coins, int sum) {
        n = coins.size();
        
        // return top_down(coins, sum);
        // return bottom_up(coins, sum);
        return space_optimized(coins, sum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends