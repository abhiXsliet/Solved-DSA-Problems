// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    bool solve(vector<int> &arr, int total, int i, int sum, vector<vector<int>> &dp) {
        if (i >= n || sum <= 0) {
            return sum == 0;
        }    
        
        if (dp[i][sum] != -1) 
            return dp[i][sum];
        
        bool op1 = solve(arr, total, i + 1, sum - arr[i], dp);
        bool op2 = solve(arr, total, i + 1, sum, dp);
        
        return dp[i][sum] = (op1 || op2);
    }
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    bool top_down(vector<int> &arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        if (total % 2) return false;
        
        int halfS = total / 2;
        vector<vector<int>> dp(n + 1, vector<int>(halfS + 1, -1));
        return solve(arr, total, 0, halfS, dp);
    }

    // TC : O(N * Sum)
    // SC : O(N * Sum)
    bool bottom_up(vector<int> &arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        if (total % 2) return false;
        
        int halfS = total / 2;
        vector<vector<int>> dp(n + 1, vector<int>(halfS + 1, 0));
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 1;
        }
        
        for (int i = n - 1; i >= 0; i --) {
            for (int sum = 0; sum <= halfS; sum ++) {
                bool op1 = (sum - arr[i] >= 0) ? dp[i + 1][sum - arr[i]] : 0;
                bool op2 = dp[i + 1][sum];
                
                dp[i][sum] = (op1 || op2);
            }
        }
        
        return dp[0][halfS];
    }

    // TC : O(N * Sum)
    // SC : O(Sum)
    bool space_optimized(vector<int> &arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        if (total % 2) return false;
        
        int halfS = total / 2;
        vector<int> curr(halfS + 1, 0), prev(halfS + 1, 0);
        curr[0] = prev[0] = 1;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int sum = 0; sum <= halfS; sum ++) {
                bool op1 = (sum - arr[i] >= 0) ? prev[sum - arr[i]] : 0;
                bool op2 = prev[sum];
                
                curr[sum] = (op1 || op2);
            }
            prev = curr;
        }
        
        return prev[halfS];
    }
  public:
    bool equalPartition(vector<int>& arr) {
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends