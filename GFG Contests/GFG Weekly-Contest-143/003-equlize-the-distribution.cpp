// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-143/problems



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int distributeCandies(int n, vector<int> &arr)
    {
        // Code Here
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
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution obj;
        cout<<obj.distributeCandies(n,arr)<<endl;
    }
}
// } Driver Code Ends