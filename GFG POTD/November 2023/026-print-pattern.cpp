// https://www.geeksforgeeks.org/problems/print-pattern3549/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        vector<int> ans;
        int val = N;
        
        while (N > 0) {
            ans.push_back(N);
            N -= 5;
        }
        
        while (N <= val) {
            ans.push_back(N);
            N += 5;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends