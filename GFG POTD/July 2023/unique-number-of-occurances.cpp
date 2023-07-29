// https://practice.geeksforgeeks.org/problems/unique-frequencies-of-not/1


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int>freq;
        for(int i=0; i<n; i++) {
            freq[arr[i]]++;
        }
        
        set<int> count;
        for(auto& i:freq) {
            if(count.find(i.second) != count.end()) {
                return false;
            }
            count.insert(i.second);
        }
        return true;
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends