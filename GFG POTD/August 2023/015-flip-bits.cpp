// https://practice.geeksforgeeks.org/problems/flip-bits0240/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int cntOne = 0;
        for(int i = 0; i < n ; i++) {
            cntOne += a[i];
        }
        
        int sum = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) 
                sum++;
            else 
                sum--;
                
            maxi = max(maxi, sum);
            
            if(sum < 0) sum = 0;
        }
        
        return maxi + cntOne;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends