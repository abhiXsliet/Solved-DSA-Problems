// https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    // LIS Variation
    // TC : O(n^2)    
    // SC : O(n^2)
    int solveTab(vector<int>& nums, int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                
                //include
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev] && nums[curr]-nums[prev] > curr-prev-1)
                    include = 1 + dp[curr+1][curr+1]; //prev=curr & +1 due to -1-index

                //exclude
                int exclude = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return n - dp[0][0];
    }
    
    // TC : O(n^2)    
    // SC : O(n)
    int solveSO(vector<int>& nums, int n) {
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev] && nums[curr]-nums[prev] > curr-prev-1)
                    include = 1 + nextRow[curr+1];

                int exclude = 0 + nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return n - nextRow[0];
    }
  public:
    int min_operations(vector<int>& nums) {
        // return solveTab(nums, nums.size()); 
        
        return solveSO(nums, nums.size());
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends