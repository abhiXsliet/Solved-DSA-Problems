// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(1)
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> result;
        for (vector<int>& interval : arr) {
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else if (result.back()[1] >= interval[0]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends