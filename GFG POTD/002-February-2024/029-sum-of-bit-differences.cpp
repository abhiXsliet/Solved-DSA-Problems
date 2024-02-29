// https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
private:
    typedef long long ll;
    
    // TC : O(32)
    ll hammingDist(int x, int y) {
        int ans = 0;
        while(x > 0 || y > 0) {
            if ((x & 1) != (y & 1)) {
                ans ++;
            }
            x >>= 1;
            y >>= 1;
        }
        return ans;
    }
    
    // TC : O(N^2)
    ll solve_brute(int arr[], int n) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] != arr[j]) {
                    ans += hammingDist(arr[i], arr[j]) * 2;
                }
            }
        }
        return ans;
    }
    
    // TC : O(N)
    ll solve_optimal(int arr[], int n) {
        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            
            ll x = 0; // with ith bit set
            for (int j = 0; j < n; j++) {
                // check the ith bit is set or not
                // if ((arr[j] >> i) & 1) x ++;     // way - 1
                
                if (arr[j] & (1 << i)) x ++;        // way - 2
            }
            
            // all permuations : n - x = y => x*y*2
            ll y = n - x;
            ans += x*y*2;
        }
        return ans;
    }
public:
	long long sumBitDifferences(int arr[], int n) {
	   // return solve_brute(arr, n);
	   
	   return solve_optimal(arr, n);
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends