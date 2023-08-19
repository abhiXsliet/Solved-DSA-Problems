// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // // Approach - 1
        // int totSum = (n * (n + 1)) / 2;
        // int sum = 0;
        // for(int i = 0; i < n - 1; i++) {
        //     sum += array[i];
        // }
        // return totSum - sum;
        
        
        // Approach - 2
        int xorAns = 0;
        for(int i = 0; i < n - 1; i++) {
            xorAns = xorAns ^ array[i];
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            res ^= i;
        }
        
        return res^xorAns;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends