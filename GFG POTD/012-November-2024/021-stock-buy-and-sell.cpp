// https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int solveMem(vector<int>& prices, int start, int end, int flag, vector<vector<int>>& dp) {
        if(start == end)
            return 0;

        if(dp[start][flag] != -1)
            return dp[start][flag];

        int profit = 0;
        if(flag) {
            //we can buy or skip -> buy or skipBuy if flag = 1 else sell
            int buy = -prices[start] + solveMem(prices, start+1, end, 0, dp);
            int skipBuy = 0 + solveMem(prices, start+1, end, 1, dp);
            profit = max(buy, skipBuy);

        } else {
            //we can sell or skip -> sell or skipSell if flag = 0 else buy
            int sell = +prices[start] + solveMem(prices, start+1, end, 1, dp);
            int skipSell = 0 + solveMem(prices, start+1, end, 0, dp);
            profit = max(sell, skipSell);
        }
        return dp[start][flag] = profit;
    }

    // TC : O(N)
    // SC : O(N)
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));

        for(int start = n-1; start >=0; start--) {
            for(int flag = 0; flag<=1; flag++) {

                int profit = 0;
                if(flag) {
                    //we can buy or skip -> buy or skipBuy if flag = 1 else sell
                    int buy = -prices[start] + dp[start+1][0];
                    int skipBuy = 0 + dp[start+1][1];
                    profit = max(buy, skipBuy);

                } else {
                    //we can sell or skip -> sell or skipSell if flag = 0 else buy
                    int sell = +prices[start] + dp[start+1][1];
                    int skipSell = 0 + dp[start+1][0];
                    profit = max(sell, skipSell);
                }
                dp[start][flag] = profit;
            }
        }
        return dp[0][1];
    }
  
    // TC : O(N)
    // SC : O(1)
    int solveSO(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int start = n-1; start >=0; start--) {
            for(int flag = 0; flag<=1; flag++) {

                int profit = 0;
                if(flag) {
                    //we can buy or skip -> buy or skipBuy if flag = 1 else sell
                    int buy = -prices[start] + next[0];
                    int skipBuy = 0 + next[1];
                    profit = max(buy, skipBuy);

                } else {
                    //we can sell or skip -> sell or skipSell if flag = 0 else buy
                    int sell = +prices[start] + next[1];
                    int skipSell = 0 + next[0];
                    profit = max(sell, skipSell);
                }
                curr[flag] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
  public:
    int maximumProfit(vector<int> &prices) {
        // vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        // return solveMem(prices, 0, prices.size(), 1, dp);
        
        // return solveTab(prices);
        
        return solveSO(prices);
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends