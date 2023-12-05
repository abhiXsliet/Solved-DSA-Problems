// https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // TC = O(N)
    // SC = O(1)
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        
        int maxEle = arr[n - 1];
        int minEle = arr[0];
        
        int ans = maxEle - minEle;
        
        // partationing at different indexes and finding max and min
        for (int i = 1; i < n; i++) {
            // choti value ko increase and badi ko decrease
            int maxi = max(arr[i - 1] + k, maxEle - k);
            int mini = min(minEle + k, arr[i] - k);
            
            if (mini < 0) continue;
            else {
                ans = min(ans, maxi - mini);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends