#include <bits/stdc++.h>
using namespace std;

void dfs(int currIdx, vector<int>& arr, vector<int>& dp,
         vector<int>& path, vector<vector<int>>& allLIS) {
    path.push_back(arr[currIdx]);

    if (dp[currIdx] == 1) {
        vector<int> temp = path;
        reverse(temp.begin(), temp.end());
        allLIS.push_back(temp);
    } else {
        for (int prev = currIdx - 1; prev >= 0; --prev) {
            if (arr[prev] < arr[currIdx] && dp[prev] == dp[currIdx] - 1) {
                dfs(prev, arr, dp, path, allLIS);
            }
        }
    }

    path.pop_back();
}

// DP (find LIS)	: O(n²)
// DFS (all paths)	: O(k × L)
// Total	        : O(n² + k × L)
vector<vector<int>> findAllLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    // Step 1: Compute LIS Lengths using DP
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLen = *max_element(dp.begin(), dp.end());
    vector<vector<int>> allLIS;

    // Step 2: Backtrack from every index with LIS length == maxLen
    for (int i = 0; i < n; ++i) {
        if (dp[i] == maxLen) {
            vector<int> path;
            dfs(i, arr, dp, path, allLIS);
        }
    }

    return allLIS;
}

int main() {
    vector<int> arr = {1, 3, 5, 4, 7};

    vector<vector<int>> allLIS = findAllLIS(arr);

    cout << "All Longest Increasing Subsequences:\n";
    for (const auto& seq : allLIS) {
        for (int x : seq) cout << x << " ";
        cout << "\n";
    }

    return 0;
}