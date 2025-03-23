// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &arr, int i, vector<int> &dp) {
        if (i >= n - 1) return 0;
        if (dp[i] != -1) return dp[i];
        
        int ans = 1e5;
        for (int jump = 1; jump <= arr[i]; jump ++) {
            ans = min(ans, 1 + solve(arr, i + jump, dp));
        }
        return dp[i] = ans;
    }
    
    // TC : O(N^2)
    // SC : O(N)
    int way_1(vector<int> &arr) {
        vector<int> dp(n + 1, -1);
        int ans = solve(arr, 0, dp);
        return ans == 1e5 ? -1 : ans;
    }

    // TC : O(N^2)
    // SC : O(N)
    int bottom_up(vector<int> &arr) {
        vector<int> dp(n + 1, 1e5);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i --) {
            int ans = 1e5;
            for (int jump = 1; jump <= arr[i]; jump ++) {
                if (i + jump < n)   
                    ans = min(ans, 1 + dp[i + jump]);
            }
            dp[i] = ans;
        }
        int res = dp[0];
        return res == 1e5 ? -1 : res;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(vector<int> &arr) {
        int farthest = 0, end = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i ++) {
            farthest = max(farthest, i + arr[i]);
            if (i == end) {
                jumps += 1;
                end = farthest;
                if (end == i) return -1;
            }
        }
        return jumps;
    }
  public:
    int minJumps(vector<int>& arr) {
        n = arr.size();
        
        // return way_1(arr);
        // return bottom_up(arr);
        return optimal(arr);        // GREEDY
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends