// https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(NlogN + MlogM + NlogM)
    // SC : O(1)
    int approach_1(int a[], int n, int b[], int m) {
        int sum_1 = accumulate(a, a + n, 0);
        int sum_2 = accumulate(b, b + m, 0);
        
        if ((sum_1 + sum_2) % 2) return -1;
        
        int tar = (sum_1 + sum_2) / 2;
        tar = abs(tar - sum_2);
        
        sort(a, a + n);
        sort(b, b + m);
        
        for (int i = 0; i < n; i ++) {
            int lo = 0, hi = m - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (abs(b[mid] - a[i]) == tar) {
                    return 1;
                } else if (abs(b[mid] - a[i]) > tar) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        
        return -1;
    }
    
    // TC : O(NlogN + MlogM)
    // SC : O(1)
    int approach_2(int a[], int n, int b[], int m) {
        int sum_1 = accumulate(a, a + n, 0);
        int sum_2 = accumulate(b, b + m, 0);
        
        if ((sum_1 + sum_2) % 2) return -1;
        
        int tar = (sum_1 + sum_2) / 2;
        tar = abs(tar - sum_2);
        
        sort(a, a + n);
        sort(b, b + m);
        
        int l = 0, r = m - 1;
        while (l < n && r >= 0) {
            int val = a[l] + b[r];
            if (val == tar) {
                return 1;
            } else if (val > tar) {
                r --;
            } else {
                l ++;
            }
        }
        
        return -1;
    }
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // return approach_1(a, n, b, m);   // BS
            
        return approach_1(a, n, b, m);      // 2-pointer
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends