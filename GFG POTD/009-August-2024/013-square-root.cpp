// https://www.geeksforgeeks.org/problems/square-root/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  private:
    // TC : O(log(N))
    // SC : O(1)
    ll approach_2(ll n) {
        ll low  = 1;
        ll high = n / 2;
        ll ans  = 1;
        while (low <= high) {
            ll mid = (low + high) >> 1;
            if (mid * mid <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
  public:
    long long int floorSqrt(long long int n) {
        // return sqrt(n);
        
        return approach_2(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}
// } Driver Code Ends