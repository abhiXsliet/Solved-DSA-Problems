// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int solve(vector<int>& arr, int n, int curr, int prev, vector<vector<int>> &dp) {
        if (curr == n) return 0;
        
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        
        int incl = 0;
        if (prev == -1 || arr[curr] > arr[prev]) {
            incl = 1 + solve(arr, n, curr + 1, curr, dp);
        }
        int excl = solve(arr, n, curr + 1,  prev, dp);
        
        return dp[curr][prev + 1] = max(incl, excl);
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int approach_1(vector<int>& arr, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, n, 0, -1, dp);
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int approach_2(vector<int>& arr, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int curr = n - 1; curr >= 0; curr --) {
            for (int prev = curr - 1; prev >= -1; prev --) {
                int incl = 0;
                if (prev == -1 || arr[curr] > arr[prev]) {
                    incl = 1 + dp[curr + 1][curr + 1];
                }
                int excl = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(incl, excl);
            }
        }
        
        return dp[0][-1+1];
    }
    
    // TC : O(N^2)
    // SC : O(N)
    int approach_3(vector<int>& arr, int n) {
        vector<int> currRow(n + 1, 0), prevRow(n + 1, 0);
        
        for (int curr = n - 1; curr >= 0; curr --) {
            for (int prev = curr - 1; prev >= -1; prev --) {
                int incl = 0;
                if (prev == -1 || arr[curr] > arr[prev]) {
                    incl = 1 + prevRow[curr + 1];
                }
                int excl = prevRow[prev + 1];
                currRow[prev + 1] = max(incl, excl);
            }
            prevRow = currRow;
        }
        
        return currRow[-1+1];
    }

    // TC : O(N^2)
    // SC : O(N)
    int approach_4(vector<int>& arr, int n) {
        vector<int> dp(n, 1);    // dp[i] : LIS ending at index i
        int maxLIS = 0;
        for (int i = 0; i < n; i ++) {  // curr-element (i)
            for (int j = 0; j < i; j ++) {  // prev-element (j)
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }
        return maxLIS;
    }
    
    // TC : O(N^2)
    // SC : O(N)
    int approach_4_print(vector<int>& arr, int n) {
        vector<int> dp(n, 1);   // dp[i] : LIS ending at index i
        vector<int> track(n);   // track the previous picked indices for lis 
        
        int lastIdx = 0;
        int maxLIS = 0;
        for (int i = 0; i < n; i ++) {  // curr-element (i)
            track[i] = i;
            for (int j = 0; j < i; j ++) {  // prev-element (j)
                if (arr[j] < arr[i] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    track[i] = j;
                }
            }
            if (dp[i] > maxLIS) {
                maxLIS = dp[i];
                lastIdx = i;
            }
        }
    /*
        // code to print lis
        vector<int> lis;
        lis.push_back(arr[lastIdx]);
        while (track[lastIdx] != lastIdx) {
            lastIdx = track[lastIdx];
            lis.push_back(arr[lastIdx]);
        }
        reverse(begin(lis), end(lis));
    */
        return maxLIS;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_5(vector<int>& arr, int n) {
        vector<int> result;
        for (int i = 0; i < n; i ++) {
            if (result.empty() || arr[i] > result.back()) {
                result.push_back(arr[i]);
            } else {
                int idx = lower_bound(begin(result), end(result), arr[i]) - begin(result);
                result[idx] = arr[i];
            }
        }
        return result.size();
    }
  public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        // return approach_1(arr, n);   // top-down
        // return approach_2(arr, n);   // bottom-up
        // return approach_3(arr, n);   // bottom-up : space optimized
        // return approach_4(arr, n);   // bottom-up : print LIS
        // return approach_4_print(arr, n);   // bottom-up : print LIS
        return approach_5(arr, n);   // optimal : binary-search
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends