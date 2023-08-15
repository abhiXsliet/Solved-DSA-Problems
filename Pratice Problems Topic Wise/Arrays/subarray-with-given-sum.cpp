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
        int l = 0, r = 0;
        long long add = 0;
        for(int i = 0; i < n; i++) {
            add += arr[i];
            
            while( add > s ) {
                add -= arr[l];
                l++;
            }
            
            if(add == s) {
                if(add == 0){
                    ans.push_back(-1);
                    return ans;
                }else {
                    ans.push_back(l+1);
                    ans.push_back(i+1);
                    return ans;
                }
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