// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    // TC : O(N)
    // SC : O(1)
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i < n; i++) {
            // arr[i] is compared with arr[2*i + 1] and arr[2*i + 2] since they are left and right child respectively
            if ( (2*i + 1 < n && arr[i] < arr[2*i + 1]) ||
                 (2*i + 2 < n && arr[i] < arr[2*i + 2]) )
                 return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends