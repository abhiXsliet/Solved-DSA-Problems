// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1);
        vector<int> track(n);
        int lastIdx = 0;
        int maxLisLen = 0;
        for (int i = 0; i < n; i ++) {
            track[i] = i;
            for (int j = 0; j < i; j ++) {
                if (arr[j] < arr[i] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    track[i] = j;
                }
            }
            if (dp[i] > maxLisLen) {
                maxLisLen = dp[i];
                lastIdx = i;
            }
        }

        vector<int> lis;
        lis.push_back(arr[lastIdx]);
        while (track[lastIdx] != lastIdx) {
            lastIdx = track[lastIdx];
            lis.push_back(arr[lastIdx]);
        }
        
        reverse(begin(lis), end(lis));
        
        return lis;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends