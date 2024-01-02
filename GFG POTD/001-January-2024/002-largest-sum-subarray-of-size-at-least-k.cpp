// https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1




//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    typedef long long int ll;
    
    // TC : O(N)
    // SC : O(N)
    ll solve_approach_1(ll arr[], ll n, ll k) {
        vector<int> maxSum((int)n, 0);
        int curr = 0;
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            curr += arr[i];
            maxi = max((int)arr[i], curr);
            maxSum[i] = maxi;
            
            if (curr < 0) curr = 0;
        }
        
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        ll ans = sum;
        for (int i = (int)k; i < n; i++) {
            sum += arr[i] - arr[i - (int)k];
            
            ans = max(ans, sum);
            
            ans = max(ans, sum + maxSum[i - (int)k]);
        }
        
        return ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    ll solve_approach_2(ll arr[], ll n, ll k) {
        // store the suffix sum
        vector<ll> dp(n+1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = arr[i] + dp[i + 1];
            // if dp[i] < 0 then it is better to take 0
            dp[i] = max(dp[i], 0LL);
        }
        
        ll ans = INT_MIN;
        
        ll curr_sum = 0;
        for (int i = 0; i < k; i++) {
            curr_sum += arr[i];
        }
        
        for (int i = k; i < n; i++) {
            ll sum = curr_sum + dp[i];
            ans    = max(ans, sum);
            
            curr_sum += arr[i];
            curr_sum -= arr[i - k];
        }
        
        return max(ans, curr_sum);
    }
    
    // TC : O(N)
    // SC : O(1)
    ll solve_approach_3(ll arr[], ll n, ll k) {
        ll ans  = INT_MIN;
        ll sum  = 0;
        ll last = 0;
        ll j    = 0;
        
        for (ll i = 0; i < n; i++) {
            sum += arr[i];
            
            if (i - j + 1 == k) {
                ans = max(ans, sum);
            }
            else if (i - j + 1 > k) {
                last += arr[j];
                j ++;
                
                if (last < 0) {
                    sum -= last;
                    last = 0;
                }
                
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        // return solve_approach_1(a, n, k);
        
        return solve_approach_2(a, n, k);
        
        return solve_approach_3(a, n, k);
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    typedef long long int ll;
    
    // TC : O(N)
    // SC : O(N)
    ll solve_approach_1(ll arr[], ll n, ll k) {
        vector<int> maxSum((int)n, 0);
        int curr = 0;
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            curr += arr[i];
            maxi = max((int)arr[i], curr);
            maxSum[i] = maxi;
            
            if (curr < 0) curr = 0;
        }
        
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        ll ans = sum;
        for (int i = (int)k; i < n; i++) {
            sum += arr[i] - arr[i - (int)k];
            
            ans = max(ans, sum);
            
            ans = max(ans, sum + maxSum[i - (int)k]);
        }
        
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    ll solve_approach_2(ll arr[], ll n, ll k) {
        ll ans  = INT_MIN;
        ll sum  = 0;
        ll last = 0;
        ll j    = 0;
        
        for (ll i = 0; i < n; i++) {
            sum += arr[i];
            
            if (i - j + 1 == k) {
                ans = max(ans, sum);
            }
            else if (i - j + 1 > k) {
                last += arr[j];
                j ++;
                
                if (last < 0) {
                    sum -= last;
                    last = 0;
                }
                
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        // return solve_approach_1(a, n, k);
        
        return solve_approach_2(a, n, k);
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends