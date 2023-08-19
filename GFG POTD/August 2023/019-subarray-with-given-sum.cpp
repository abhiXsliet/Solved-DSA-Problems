// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> ans;
        int left = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];

            while(sum > s) {
                sum -= arr[left++];
            }
            
            // edge case 
            if(s == 0) return {-1}; 
            
            if(sum == s) {
                ans.push_back(left+1);
                ans.push_back(i+1);
                return ans;
            } 
        }
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends