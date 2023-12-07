// https://www.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    // TC = O(N^2)
    // SC = O(1)
    long solve_brute(int arr[], int n, int l, int r) {
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int max_val = INT_MIN;
            for (int j = i; j < n; j++) {
                max_val = max(max_val, arr[j]);
                if (max_val >= l && max_val <= r) {
                    ans++;
                }
            }
        }
        return ans;
    }
    
    // TC = O(N)
    // SC = O(1)
    long solve_optimal(int arr[], int n, int l, int r) {
        int start = 0;
        int end   = 0;
        int prevCount = 0;
        long result    = 0;
        while (end < n) {
            if (arr[end] >= l && arr[end] <= r) {
                prevCount = end - start + 1;
                result   += prevCount; 
            }
            else if (arr[end] < l) {
                result   += prevCount;
            }
            else {  // arr[end] > r
                start = end + 1;
                prevCount = 0;
            }
            end ++;
        }
        return result;
    }
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // return solve_brute(a, n, L, R);
        
        return solve_optimal(a, n, L, R);
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends