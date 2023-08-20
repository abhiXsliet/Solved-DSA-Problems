// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-115/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int completeRows(int n) {
        int row = 0;
        for(int i = 1; i <= n; i++) {
            n = n - i;
            row++;
        }
        return row;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        Solution obj;
        int res = obj.completeRows(n);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends