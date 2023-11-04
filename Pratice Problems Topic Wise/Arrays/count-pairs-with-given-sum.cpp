// https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{ 
private:
    // TC = O(N)
    // SC = O(N)
    int solve_approach_1(int arr[], int n, int k) {
        int ans = 0;
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n; i++) {
            
            int target = k - arr[i];
            if (mpp.find(target) != mpp.end()) {
                ans += mpp[target];
            }
            
            mpp[arr[i]]++;
        }
        
        return ans;
    }
    
public:
    int getPairsCount(int arr[], int n, int k) {
        return solve_approach_1(arr, n, k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends