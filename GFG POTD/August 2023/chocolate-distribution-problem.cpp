// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        
        int mini = INT_MAX;
        int idx1 = 0;
        int idx2 = m-1;
        
        while(idx2 < n) {
            int diff = a[idx2] - a[idx1];
            mini = min(mini, diff);
            idx1++;
            idx2++;
        }
        return mini;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends