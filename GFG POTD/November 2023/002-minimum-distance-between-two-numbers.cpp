// https://www.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  private:
    // TC = O(N*N)
    // SC = O(N)
    int solve_brute(int arr[], int n, int x, int y) {
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] == x && arr[j] == y || arr[j] == x && arr[i] == y) {
                    ans = min(ans, abs(i - j));
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    // TC = O(N)
    // SC = O(1)
    int solve_better(int arr[], int n, int x, int y) {
        int ans = INT_MAX;
        int idx_x = -1;
        int idx_y = -1;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                idx_x = i;
                if (idx_y != -1)
                    ans = min(ans, abs(i - idx_y));
            }
            else if (arr[i] == y) {
                idx_y = i;
                if (idx_x != -1)
                    ans = min(ans, abs(i - idx_x));
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    // TC = O(N)
    // SC = O(1)
    int solve_optimal(int arr[], int n, int x, int y) {
        int ans = INT_MAX;
        int idx = -1;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == x || arr[i] == y) {
                if(idx != -1 && arr[idx] != arr[i]) {
                    ans = min(ans, abs(i - idx));
                }
                idx = i;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
  public:
    int minDist(int arr[], int n, int x, int y) {
        // return solve_brute(arr, n, x, y);
        
        // return solve_better(arr, n, x, y);
        
        return solve_optimal(arr, n, x, y);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends