// https://practice.geeksforgeeks.org/problems/fraction-pairs-with-sum-1/1



//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int, int>, int> mpp;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int g = __gcd(numerator[i], denominator[i]);
            numerator[i] = numerator[i] / g;
            denominator[i] = denominator[i] / g;
            
            int z = denominator[i] - numerator[i];
            
            if(mpp.find({z, denominator[i]}) != mpp.end()) {
                ans += mpp[{z, denominator[i]}];
            }
            mpp[{numerator[i], denominator[i]}] ++;
        }
        return ans;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends