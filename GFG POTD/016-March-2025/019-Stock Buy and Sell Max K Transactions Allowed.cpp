// https://www.geeksforgeeks.org/problems/maximum-profit4657/1





//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &prices, int i, int k, bool isBuy, vector<vector<vector<int>>> &dp) {
        if (i >= n || k == 0) return 0;
        
        if (dp[i][k][isBuy] != -1)
            return dp[i][k][isBuy];
        
        int profit = 0;
        if (isBuy) {
            int buy     = -prices[i] + solve(prices, i + 1, k, 0, dp);
            int skipBuy =  solve(prices, i + 1, k, 1, dp);
            profit      =  max(buy, skipBuy);
        } else {
            int sell     = prices[i] + solve(prices, i + 1, k - 1, 1, dp);
            int skipSell = solve(prices, i + 1, k, 0, dp);
            profit       = max(sell, skipSell);
        }
        
        return dp[i][k][isBuy] = profit;
    }
    
    // TC : O(N * K)
    // SC : O(N * K)
    int top_down(vector<int> &prices, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3, -1)));
        return solve(prices, 0, k, 1, dp);
    }

    // TC : O(N * K)
    // SC : O(N * K)
    int bottom_up(vector<int> &prices, int K) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(K + 1, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i --) {
            for (int k = 1; k <= K; k ++) {
                for (int isBuy = 0; isBuy <= 1; isBuy ++) {
                    int profit = 0;
                    if (isBuy) {
                        int buy     = -prices[i] + dp[i + 1][k][0];
                        int skipBuy =  dp[i + 1][k][1];
                        profit      =  max(buy, skipBuy);
                    } else {
                        int sell     = prices[i] + dp[i + 1][k - 1][1];
                        int skipSell = dp[i + 1][k][0];
                        profit       = max(sell, skipSell);
                    }
                    dp[i][k][isBuy] = profit;
                }
            }
        }
        return dp[0][K][1];
    }
    
    // TC : O(N * K)
    // SC : O(K)
    int space_optimized(vector<int> &prices, int K) {
        vector<vector<int>> curr(K + 1, vector<int>(3, 0)), prev(K + 1, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i --) {
            for (int k = 1; k <= K; k ++) {
                for (int isBuy = 0; isBuy <= 1; isBuy ++) {
                    int profit = 0;
                    if (isBuy) {
                        int buy     = -prices[i] + prev[k][0];
                        int skipBuy =  prev[k][1];
                        profit      =  max(buy, skipBuy);
                    } else {
                        int sell     = prices[i] + prev[k - 1][1];
                        int skipSell = prev[k][0];
                        profit       = max(sell, skipSell);
                    }
                    curr[k][isBuy] = profit;
                }
            }
            prev = curr;
        }
        return prev[K][1];
    }
  public:
    int maxProfit(vector<int>& prices, int k) {
        n = prices.size();
        
        // return top_down(prices, k);
        // return bottom_up(prices, k);
        return space_optimized(prices, k);
    }
};


//{ Driver Code Starts.
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends