// https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    public:
    // TC : O(N)
    // SC : O(N)
    int firstElementKTime(int n, int k, int a[]) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[a[i]] ++;
            if (mpp[a[i]] >= k)
                return a[i];
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends