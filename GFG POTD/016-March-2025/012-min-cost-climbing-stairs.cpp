// https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  private:
    int n;
    int solve(vector<int> &cost, int i, vector<int> &dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int op1 = solve(cost, i + 1, dp);
        int op2 = solve(cost, i + 2, dp);
        
        return dp[i] = (cost[i] + min(op1, op2));
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &cost) {
        vector<int> dp(n + 1, -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> &cost) {
        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i --) {
            int op1 = dp[i + 1];
            int op2 = dp[i + 2];
            dp[i]   = (cost[i] + min(op1, op2));
        }
        return min(dp[0], dp[1]);
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int> &cost) {
        int prev1 = 0, prev2 = 0;
        for (int i = n - 1; i >= 0; i --) {
            int op1  = prev1;
            int op2  = prev2;
            int curr = (cost[i] + min(op1, op2));
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        
        // return approach_1(cost);
        // return approach_2(cost);
        return approach_3(cost);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends