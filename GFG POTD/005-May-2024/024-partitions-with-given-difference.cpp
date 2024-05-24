// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
private:
    static const int mod = 1000000007;
    
    int fun(int pos, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if(sum < 0) return 0;
        if (pos == arr.size())
            return sum == 0 ? 1 : 0; 
            
        if (dp[pos][sum] != -1) 
            return dp[pos][sum];

        return dp[pos][sum] = (fun(pos + 1, sum, arr, dp) % mod + 
                               fun(pos + 1, sum - arr[pos], arr, dp) % mod) % mod; 
        //not take + take
    }
    
    int perfectSum(vector<int>& arr, int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= sum; i++)
            dp[0][i] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
            }
        }

        return dp[n][sum] % mod;
    }
    
    // TC : O(N*sum)
    int approach_1(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int x : arr)
            sum += x;

        if(sum < d || (sum - d) % 2 != 0)
            return 0;

        int k = (sum - d) / 2;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return fun(0, k , arr, dp);
    }
    
    int approach_2(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int x : arr)
            sum += x;

        if(sum < d || (sum - d) % 2 != 0)
            return 0;

        int k = (sum + d) / 2;

        return perfectSum(arr, n, k);
    }
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // return approach_1(n, d, arr);
        
        return approach_2(n, d, arr);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends