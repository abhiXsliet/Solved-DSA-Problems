// https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
// } Driver Code Ends

class Solution {
  private:
    typedef long long ll;
    
    // TC : O(X*Y) ~= O(N^2)
    // SC : O(X*Y) ~= O(N^2)
    ll solve(vector<int> &arr, vector<int> &brr, int x, int y, int n, vector<vector<int>>& dp) {
        if (n == 0) return 0; // Base case when all orders are processed
        
        if (x < 0 || y < 0) return INT_MIN; // If either x or y is negative, it's an invalid state
        
        if (dp[x][y] != -1) return dp[x][y];
        
        // Take the maximum of two choices:
        // 1. Waiter A takes the order and earns arr[n-1]
        // 2. Waiter B takes the order and earns brr[n-1]
        int takeA = x > 0 ? arr[n-1] + solve(arr, brr, x-1, y, n-1, dp) : 0;
        int takeB = y > 0 ? brr[n-1] + solve(arr, brr, x, y-1, n-1, dp) : 0;
        
        return dp[x][y] = max(takeA, takeB);
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    ll optimal(vector<int>& arr, vector<int>& brr, int x, int y, int n) {
        vector<pair<int, pair<int, int>>> store(n, {0, {0, 0}});    // {difference, {arr[i], brr[i]}}
        
        int i = 0, j = 0;
        while (i < n && j < n) {
            int diff = abs(arr[i] - brr[i]);
            store.push_back({diff, {arr[i], brr[i]}});
            i ++, j ++;
        }
        
        sort(rbegin(store), rend(store));
        
        ll ans = 0;
        for (auto& it : store) {
            if (x == 0) {
                ans += it.second.second;
            } else if (y == 0) {
                ans += it.second.first;
            } else if (it.second.first >= it.second.second) {
                ans += it.second.first;
                x --;
            } else {
                ans += it.second.second;
                y --;
            }
        }
        return ans;
    }
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // vector<vector<int>> dp(x+1, vector<int>(y+1, -1));
        // return solve(arr, brr, x, y, n, dp);
        
        return optimal(arr, brr, x, y, n);  // GREEDY
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}
// } Driver Code Ends