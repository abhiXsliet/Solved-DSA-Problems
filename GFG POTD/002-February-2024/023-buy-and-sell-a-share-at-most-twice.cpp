// https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1



//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    // TC = O(N * N) -> TLE
    // SC = O(1)
    int solve_brute(vector<int>& prices, int n) {
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            // max profit with one transaction and subarray price[0..i] 
            int leftMaxProfit = 0;
            int leftMinPrice  = prices[0];
            for (int j = 0; j <= i; j++) {
                leftMaxProfit = max(leftMaxProfit, prices[j] - leftMinPrice);
                leftMinPrice  = min(prices[j], leftMinPrice);
            }
            
            // max profit with one transaction and subarray price[i+1..n-1] 
            int rightMaxProfit = 0;
            int rightMaxPrice  = prices[n - 1];
            for (int j = n - 1; j >= i; j--) {
                rightMaxProfit = max(rightMaxProfit, rightMaxPrice - prices[j]);
                rightMaxPrice  = max(rightMaxPrice, prices[j]);
            }
            
            maxProfit = max(maxProfit, (leftMaxProfit + rightMaxProfit));
        }
        return maxProfit;
    }
    
    // TC = O(N)
    // SC = O(N)
    int solve_better(vector<int>& prices, int n) {
        // left[i] stores the maximum profit in subarray price[0..i] with at most one transaction
        vector<int> left (n, 0);
        
        int leftMin = prices[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        
        // right[i] stores the maximum profit in subarray price[i..n-1] with at most one transaction
        vector<int> right (n, 0);
        
        int rightMax = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            right[i]  = max(right[i+1], rightMax - prices[i]);
            rightMax  = max(rightMax, prices[i]);
        }
        
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, (left[i] + right[i]));
        }
        return maxProfit;
    }
    
    // TC = O(N)
    // SC = O(1)
    int solve_optimal_dp(vector<int>& prices, int n) {
        int first_buy   = INT_MIN;
        int first_sold  = 0;
        int second_buy  = INT_MIN;
        int second_sold = 0;
        
        for (int i = 0; i < n; i++) {
            first_buy   = max(first_buy, -prices[i]);
            first_sold  = max(first_sold, first_buy + prices[i]);    // first sold iff you have bought the first
            second_buy  = max(second_buy, first_sold - prices[i]);   // second buy iff you have sold the first
            second_sold = max(second_sold, second_buy + prices[i]);  // second sold iff you have bought the second
        }
        
        return second_sold;
    }
    
    // ------------------------------------------- Recursion + DP -----------------------------------------------------
    
    // TC = O(2 ^ N)
    // SC = O(N) -> recursive depth
    int solve_rec(vector<int>& prices, int n, int index, int flag, int limit) {
        if (index == n)   return 0;
        if (limit == 0) return 0;
        
        int profit = 0;
        if (flag) {
            int buy     = -prices[index] + solve_rec(prices, n, index+1, 0, limit);
            int skipBuy = solve_rec(prices, n, index+1, 1, limit);
            profit      = max(buy, skipBuy);
        }
        else {
            int sell    = +prices[index] + solve_rec(prices, n, index+1, 1, limit - 1);
            int skipSell= solve_rec(prices, n, index+1, 0, limit);
            profit      = max(sell, skipSell);
        }
        return profit;
    }
    
    // TC = O(N)
    // SC = O(N)
    int t[100001][2][3];
    int solve_mem(vector<int>& prices, int n, int index, int flag, int limit) {
        if (index == n)   return 0;
        if (limit == 0) return 0;
        
        if (t[index][flag][limit] != -1)
            return t[index][flag][limit];
        
        int profit = 0;
        if (flag) {
            int buy     = -prices[index] + solve_mem(prices, n, index+1, 0, limit);
            int skipBuy = solve_mem(prices, n, index+1, 1, limit);
            profit      = max(buy, skipBuy);
        }
        else {
            int sell    = +prices[index] + solve_mem(prices, n, index+1, 1, limit - 1);
            int skipSell= solve_mem(prices, n, index+1, 0, limit);
            profit      = max(sell, skipSell);
        }
        return t[index][flag][limit] = profit;
    }
    
    // TC = O(N)
    // SC = O(N)
    int solve_tab(vector<int>&prices, int n) {
        int dp[100001][2][3]; // idx, flag, limit
        memset(dp, 0, sizeof(dp));
        
        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (flag) {
                        int buy     = -prices[index] + dp[index+1][0][limit];
                        int skipBuy = dp[index+1][1][limit];
                        profit      = max(buy, skipBuy);
                    }
                    else {
                        int sell    = +prices[index] + dp[index+1][1][limit - 1];
                        int skipSell= dp[index+1][0][limit];
                        profit      = max(sell, skipSell);
                    }
                    dp[index][flag][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    
    // TC = O(N)
    // SC = O(1)
    int solve_so(vector<int>&prices, int n) {
        
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        
        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (flag) {
                        int buy     = -prices[index] + next[0][limit];
                        int skipBuy = next[1][limit];
                        profit      = max(buy, skipBuy);
                    }
                    else {
                        int sell    = +prices[index] + next[1][limit - 1];
                        int skipSell= next[0][limit];
                        profit      = max(sell, skipSell);
                    }
                    curr[flag][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[1][2];
    }
    public:
    //User function Template for C++
    int maxProfit(vector<int>&price){
        
        // return solve_brute(price, price.size());
        
        // return solve_better(price, price.size());
        
        return solve_optimal_dp(price, price.size());
        
        // ---------------------------- Recursion + DP solutions ------------------------------------------------
        
        // return solve_rec(price, price.size(), 0, 1, 2);  // flag = 1, idx = 0, transction = 2
        
        // memset(t, -1, sizeof(t));
        // return solve_mem(price, price.size(), 0, 1, 2); 
        
        // return solve_tab(price, price.size());
        
        // return solve_so(price, price.size());
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends