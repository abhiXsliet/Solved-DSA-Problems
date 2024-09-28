// https://www.geeksforgeeks.org/problems/minimal-cost/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int dp[10001];
    
    // TC : O(N*K)
    // SC : O(N)
    int solve(vector<int>& arr, int n, int k, int idx) {
        if (idx == n - 1) return 0;
        
        if (dp[idx] != -1) return dp[idx];
        
        int ans = INT_MAX;
        for (int i = 1; i <= k && idx + i < n; i ++) {
            ans = min(ans, abs(arr[idx] - arr[idx + i]) + 
                           solve(arr, n, k, idx + i));
        }
        return dp[idx] = ans;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, arr.size(), k, 0);
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
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
// } Driver Code Ends