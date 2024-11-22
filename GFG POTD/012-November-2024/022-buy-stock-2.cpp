// https://www.geeksforgeeks.org/problems/buy-stock-2/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    int brute(vector<int>& prices) {
        int n = prices.size();
        set<pair<int, int>> st;
        for (int i = 0; i < n; i ++) {
            st.insert({prices[i], i});
        }
        int maxi = 0;
        for (int i = 0; i < n; i ++) {
            int buy = prices[i];
            st.erase({buy, i});
            int sell = 0;
            if (!st.empty()) {
                sell = st.rbegin() -> first;
            }
            maxi = max(maxi, sell - buy);
        }
        return maxi;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i ++) {
            int diff = prices[i] - mini;
            profit   = max(profit, diff);
            mini     = min(mini, prices[i]);
        }
        return profit;
    }
    
    int maximumProfit(vector<int> &prices) {
        // return brute(prices);
        
        return optimal(prices);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends