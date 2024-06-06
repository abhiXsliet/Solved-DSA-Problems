// https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  public:
    typedef long long ll;
    
    // TC : O(N)
    // SC : O(1)
    ll max_sum(int a[], int n) {
        ll sum = accumulate(a, a + n, 0LL);
        
        // Initial Sum Without Any Rotation: Rotation-0 
        ll sumI = 0; 
        for (int i = 0; i < n; i ++) {
            sumI += (a[i] * (ll)i);
        }
        
        ll result = sumI;
        for (int i = 1; i < n; i ++) {
            // FORMULA : S(i+1) = S(i) + sum - N*arr[n - i] 
            ll sumNext = sumI + sum - ((ll)n * a[n - i]);
            result     = max(result, sumNext);
            sumI       = sumNext;
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}
// } Driver Code Ends