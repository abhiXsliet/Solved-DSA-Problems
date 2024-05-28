// https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};
// } Driver Code Ends

class Solution {
  private:
    int solve(int ind, vector<int>& cost, int w, vector<vector<int>>&dp){
        if(w == 0){
            return 0;
        }
        if(ind >= cost.size() || ind + 1 > w){
            return 1e9;
        }
        
        if(dp[ind][w] != -1) return dp[ind][w];
        
        int a, b;
        if(cost[ind] != -1 && ind + 1 <= w){
            a = cost[ind] + solve(ind, cost, w - (ind + 1), dp);
        }
        b = solve(ind + 1, cost, w, dp);
        
        return dp[ind][w] = min(a,b);
    }
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<vector<int>>dp(n + 1, vector<int>(w + 1, -1));
        int ans = solve(0, cost, w, dp);
        
        if(ans >= 1e9) ans = -1;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}
// } Driver Code Ends