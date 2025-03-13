// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &val, vector<int> &wt, int i, int cap, vector<vector<int>> &dp) {
        if (i >= n || !cap) return 0;    
        
        if (dp[i][cap] != -1) return dp[i][cap];
        
        int take = 0;
        if (cap >= wt[i]) {
            take = val[i] + solve(val, wt, i + 1, cap - wt[i], dp);
        }
        int notT = solve(val, wt, i + 1, cap, dp);
        
        return dp[i][cap] = max(take, notT);
    }
    
    // TC : O(N * W)
    // SC : O(N * W)
    int top_down(vector<int> &val, vector<int> &wt, int W) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return solve(val, wt, 0, W, dp);
    }
    
    // TC : O(N * W)
    // SC : O(N * W)
    int bottom_up(vector<int> &val, vector<int> &wt, int W) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for (int i = n - 1; i >= 0; i --) {
            for (int cap = 0; cap <= W; cap ++) {
                int take = 0;
                if (cap >= wt[i]) {
                    take = val[i] + dp[i + 1][cap - wt[i]];
                }
                int notT = dp[i + 1][cap];
                
                dp[i][cap] = max(take, notT);
            }
        }
        
        return dp[0][W];
    }

    // TC : O(N * W)
    // SC : O(N * W)
    int space_optimized(vector<int> &val, vector<int> &wt, int W) {
        vector<int> curr(W + 1, 0), prev(W + 1, 0);
        
        for (int i = n - 1; i >= 0; i --) {
            for (int cap = 0; cap <= W; cap ++) {
                int take = 0;
                if (cap >= wt[i]) {
                    take = val[i] + prev[cap - wt[i]];
                }
                int notT = prev[cap];
                
                curr[cap] = max(take, notT);
            }
            prev = curr;
        }
        
        return prev[W];
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        n = val.size();
        
        // return top_down(val, wt, W);
        // return bottom_up(val, wt, W);
        return space_optimized(val, wt, W);
    }
};

//{ Driver Code Starts.
int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends