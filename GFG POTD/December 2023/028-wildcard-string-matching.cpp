// https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    private:
    int t[1001][1001];
    // TC : O(2^(N+M))
    // SC : O(N+M) -> Recursive Depth
    bool solve_rec(string& s, string& p, int i, int j) {
        // both string consumed
        if (i == s.length() && j == p.length())
            return true;
        
        // string 's' remaining and pattern 'p' consumed
        if (i < s.length() &&  j == p.length())
            return false;
        
        // string 's' consumed and pattern 'p' remaining
        if (i == s.length()&& j < p.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') 
                    return false;
            }
            return true;
        }
        
        // match case
        if (s[i] == p[j] || p[j] == '?') {
            return solve_rec(s, p, i + 1, j + 1);
        }
        // match case
        else if (p[j] == '*') {
            return ( solve_rec(s, p, i + 1, j) || solve_rec(s, p, i, j + 1) );
        }
        // does not match case
        else return false;
    }
    
    // TC : O(N*M)
    // SC : O(N*M)
    bool solve_mem(string& s, string& p, int i, int j) {
        // both string consumed
        if (i == s.length() && j == p.length())
            return true;
        
        // string 's' remaining and pattern 'p' consumed
        if (i < s.length() &&  j == p.length())
            return false;
        
        // string 's' consumed and pattern 'p' remaining
        if (i == s.length()&& j < p.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') 
                    return false;
            }
            return true;
        }
        
        if (t[i][j] != -1)
            return t[i][j];
        
        // match case
        if (s[i] == p[j] || p[j] == '?') {
            return t[i][j] = solve_mem(s, p, i + 1, j + 1);
        }
        // match case
        else if (p[j] == '*') {
            return t[i][j] = ( solve_mem(s, p, i + 1, j) || solve_mem(s, p, i, j + 1) );
        }
        // does not match case
        else return t[i][j] = false;
    }
    public:
    bool match(string wild, string pattern)
    {
        // return solve_rec(pattern, wild, 0, 0);
        
        memset(t, -1, sizeof(t));
        return solve_mem(pattern, wild, 0, 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends