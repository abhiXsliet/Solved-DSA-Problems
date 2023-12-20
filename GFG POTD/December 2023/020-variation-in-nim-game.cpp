// https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findWinner(int n, int A[]){
        int num = 0;
        for (int i = 0; i < n; i++) {
            num = num ^ A[i];
        }
        
        if (num == 0) return 1;
        if (n % 2 == 0) return 1;
        return 2;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends