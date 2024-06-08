// https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int brute(int arr1[], int arr2[], int n) {
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (arr1[i] != arr2[j]) {
                return i;
            }
            i ++, j ++;
        }
        return i;
    }
        
    // TC : O(log(N))
    // SC : O(1)
    int optimal(int arr1[], int arr2[], int n) {
        int lo = 0, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr1[mid] == arr2[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // return brute(arr1, arr2, n);
        
        return optimal(arr1, arr2, n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends