// https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int M = 1003;
    int t[1001][1001][2];
    
    // TC : O(N^3)
    // SC : O(N^2)
    int mem(string s, int i, int j, int isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if (t[i][j][isTrue] != -1) return t[i][j][isTrue];
        
        int ways = 0;
        
        for (int idx = i + 1; idx < j; idx += 2) {
            int lT = mem(s, i, idx - 1, 1); // left true
            int lF = mem(s, i, idx - 1, 0); // left false
            int rT = mem(s, idx + 1, j, 1); // right true
            int rF = mem(s, idx + 1, j, 0); // right false
            
            if (s[idx] == '&') {
                if (isTrue) 
                    ways = (ways + (lT * rT) % M) % M;
                else 
                    ways = (ways + (lT * rF) % M + (lF * rT) % M + (lF * rF) % M) % M;
            }
            else if (s[idx] == '|') {
                if (isTrue) 
                    ways = (ways + (lT * rF) % M + (lF * rT) % M + (lT * rT) % M) % M;
                else 
                    ways = (ways + (lF * rF) % M) % M;
            }
            else {
                // T^T = F, F^F = F, F^T = T, T^F = T
                if (isTrue) 
                    ways = (ways + (lF * rT) % M + (lT * rF) % M) % M;
                else 
                    ways = (ways + (lT * rT) % M + (lF * rF) % M) % M;
            }
        }
        return t[i][j][isTrue] = ways;
    }
public:
    int countWays(int n, string s){
        memset(t, -1, sizeof(t));
        return mem(s, 0, s.length() - 1, 1);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends