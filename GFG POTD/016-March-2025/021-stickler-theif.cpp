// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &arr, int i, vector<int> &dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int take = arr[i] + solve(arr, i + 2, dp);
        int notT = solve(arr, i + 1, dp);
        
        return dp[i] = max(take, notT);
    }
    
    // TC : O(N)
    // SC : O(N)
    int top_down(vector<int> &arr) {
        vector<int> dp(n + 1, -1);
        return solve(arr, 0, dp);
    }

    // TC : O(N)
    // SC : O(N)
    int bottom_up(vector<int> &arr) {
        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i --) {
            int take = arr[i] + dp[i + 2];
            int notT = dp[i + 1];

            dp[i] = max(take, notT);
        }
        return dp[0];
    }
    
    // TC : O(N)
    // SC : O(1)
    int space_optimized(vector<int> &arr) {
        int prev1 = 0, prev2 = 0;
        for (int i = n - 1; i >= 0; i --) {
            int take = arr[i] + prev2;
            int notT = prev1;

            int curr = max(take, notT);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
  public:
    int findMaxSum(vector<int>& arr) {
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends