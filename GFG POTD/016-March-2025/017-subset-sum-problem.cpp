// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1




#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    int n;
    
    bool solve(vector<int> &arr, int i, int tar, vector<vector<int>> &dp) {
        if (tar <= 0) return tar == 0;
        if (i   >= n) return 0;
        
        if (dp[i][tar] != -1) return dp[i][tar];
        
        int take = solve(arr, i + 1, tar - arr[i], dp);
        int notT = solve(arr, i + 1, tar, dp);
        
        return dp[i][tar] = (take | notT);
    }
    
    // TC : O(tar * N)
    // SC : O(tar * N)
    int top_down(vector<int> &arr, int tar) {
        vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));
        return solve(arr, 0, tar, dp);
    }

    // TC : O(tar * N)
    // SC : O(tar * N)
    int bottom_up(vector<int> &arr, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int j = 0; j <= n; j ++) {
            dp[j][0] = 1;   // making target == 0 always possible by choosing no elements
        }
        
        for (int i = n - 1; i >= 0; i --) {
            for (int tar = 1; tar <= target; tar ++) {
                int take = 0;
                if (tar - arr[i] >= 0) 
                    take = dp[i + 1][tar - arr[i]];
                int notT = dp[i + 1][tar];

                dp[i][tar] = (take | notT);
            }
        }
        return dp[0][target];
    }
    
    // TC : O(tar * N)
    // SC : O(tar)
    int space_optimized(vector<int> &arr, int target) {
        vector<int> curr(target + 1, 0), prev(target + 1, 0);

        curr[0] = 1; // If the target is 0, it's always possible (by choosing no elements)
        
        for (int i = n - 1; i >= 0; i --) {
            prev[0] = 1;    // reset base for the current row
            for (int tar = 1; tar <= target; tar ++) {
                int take = 0;
                if (tar - arr[i] >= 0) 
                    take = prev[tar - arr[i]];
                int notT = prev[tar];

                curr[tar] = (take | notT);
            }
            prev = curr;
        }
        return prev[target];
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        n = arr.size();
        
        // return top_down(arr, target);
        // return bottom_up(arr, target);
        return space_optimized(arr, target);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends