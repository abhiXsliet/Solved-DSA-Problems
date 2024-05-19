// https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1



//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
    // TC : O(log(N))
    // SC : O(1)
    int approach_1(int n, int k, int arr[]) {
        int lb = lower_bound(arr, arr + n, k) - arr;
        
        if (arr[lb] == k) return k;
        
        if (lb > 0) {
            if (k - arr[lb - 1] < arr[lb] - k) 
                return arr[lb - 1];
            else return arr[lb];
        }
        
        return 0; // flow not reach here
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int approach_2(int n, int k, int arr[]) {
        int l = 0, r = n;
        int ans = arr[0];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (abs(k - arr[mid]) == abs(k - ans))
                ans = max(ans, arr[mid]);
            else if (abs(k - arr[mid]) < abs(k - ans))
                ans = arr[mid];
            
            if (arr[mid] == k)
                return arr[mid];
            else if (arr[mid] < k)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return ans;
    }
    public:
    int findClosest( int n, int k,int arr[]) { 
        // return approach_1(n, k, arr);
        
        return approach_2(n, k, arr);
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}
// } Driver Code Ends