// https://www.geeksforgeeks.org/problems/number-of-coins1824/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &coins, int i, int sum, vector<vector<int>> &dp) {
        if (sum == 0) return 0;
        if (i >= n || sum < 0)
            return 1e5;
            
        if (dp[i][sum] != -1)
            return dp[i][sum];
            
        int take = 1 + solve(coins, i, sum - coins[i], dp);
        int notT = solve(coins, i + 1, sum, dp);
        
        return dp[i][sum] = min(take, notT);
    }
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int top_down(vector<int> &coins, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        int ans = solve(coins, 0, sum, dp);
        return ans == 1e5 ? -1 : ans;
    }

    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int bottom_up(vector<int> &coins, int summ) {
        vector<vector<int>> dp(n + 1, vector<int>(summ + 1, 1e5));
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 0;
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int sum = 0; sum <= summ; sum ++) {
                int take = (sum - coins[i] >= 0) ? 1 + dp[i][sum - coins[i]] : 1e5;
                int notT = dp[i + 1][sum];
                dp[i][sum] = min(take, notT);
            }
        }
        int ans = dp[0][summ];
        return ans == 1e5 ? -1 : ans;
    }
    
    // TC : O(N * Sum)
    // SC : O(Sum)
    int space_optimized(vector<int> &coins, int summ) {
        vector<int> curr(summ + 1, 1e5), prev(summ + 1, 1e5);
        curr[0] = 0;
        
        for (int i = n - 1; i >= 0; i --) {
            prev[0] = 0;
            for (int sum = 0; sum <= summ; sum ++) {
                int take = (sum - coins[i] >= 0) ? 1 + curr[sum - coins[i]] : 1e5;
                int notT = prev[sum];
                curr[sum] = min(take, notT);
            }
            prev = curr;
        }
        int ans = prev[summ];
        return ans == 1e5 ? -1 : ans;
    }
  public:
    int minCoins(vector<int> &coins, int sum) {
        n = coins.size();
        
        // return top_down(coins, sum);
        // return bottom_up(coins, sum);
        return space_optimized(coins, sum);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends