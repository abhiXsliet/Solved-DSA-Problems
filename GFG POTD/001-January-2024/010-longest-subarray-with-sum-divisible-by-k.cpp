// https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function template for C++

class Solution{
private:
    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(int arr[], int n, int k) {
        int ans = 0;
	    
	    unordered_map<int, int> mpp; // {remainder, indexes}
	    mpp[0] = -1;    // 0 coming on -1 index
	        
	    int sum = 0;
	    int rem = 0;
	    
	    for (int i = 0; i < n; i++) {
	        sum += arr[i];
	        rem = sum % k;
	        
	        if (rem < 0) {
	            rem += k;
	        }
	        
	        // if the remainder index are available then calculate the length
	        if (mpp.find(rem) != mpp.end()) {
	            ans = max(ans, i - mpp[rem]);
	        }
	        // otherwise put the remainder at their respective index
	        else {
	            mpp[rem] = i;
	        }
	    }
	    
	    return ans;
    }
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k) {
	    return solve_approach_1(arr, n, k);
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends