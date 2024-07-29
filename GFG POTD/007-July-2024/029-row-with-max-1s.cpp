// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N*M)
    // SC : O(1)
    int brute(vector<vector<int>>& arr, int n, int m) {
        int maxi   = 0;
	    int minIdx = -1;
	    
	    for (int i = 0; i < n; i++) {
	        int cnt = 0;
	        for (int j = 0; j < m; j++) {
	            if (arr[i][j] == 1) cnt++;
	        }
	        if (maxi < cnt) {
	            maxi = cnt;
	            minIdx = i;
	        }
	    }
	    return minIdx;
    }
    
    // TC : O(N*log(M))
    // SC : O(1)
    int better(vector<vector<int>>& arr, int n, int m) {
        int ans = -1;
        int maxi = 0;
        
        for (int i = 0; i < n; i ++) {
            
            int low = 0, high = m;
            int cntOnes = 0;
            
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (arr[i][mid] == 1) {
                    cntOnes = m - mid;
                    high    = mid - 1;
                    
                } else {
                    low = mid + 1;
                }
            }
            if (cntOnes > maxi) {
                maxi = cntOnes;
                ans  = i;
            }
        }
        return ans;
    }
    
    // TC : O(M + N)
    // SC : O(1)
    int optimal(vector<vector<int>>& arr, int n, int m) {
        int maxRowIndex = -1;
        int j = m - 1;  // Start from the top-right corner
        for (int i = 0; i < n; i++) {
            while (j >= 0 && arr[i][j] == 1) {
                j--;  // Move left if we encounter a 1
                maxRowIndex = i;  // Update the row index
            }
        }
        return maxRowIndex;
    }
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // return brute(arr, arr.size(), arr[0].size());    // Brute
        // return better(arr, arr.size(), arr[0].size());   // BS
        return optimal(arr, arr.size(), arr[0].size());     // Traverse from top-right corner
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends