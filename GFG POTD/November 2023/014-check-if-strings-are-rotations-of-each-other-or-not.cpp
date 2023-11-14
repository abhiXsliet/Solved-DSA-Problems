// https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    // TC = O(n) where n is the length of s1
    // SC = O(1)
    bool solve_stl(string& s1, string& s2) {
        // `string::npos` represents the "not found" condition in C++ string operations.
        return ((s1 + s1).find(s2) != string::npos);
    }
    
    // TC = O(N)
    // SC = O(1)
    bool solve_iterative(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        
        if (n == 1 && m == 1)
            return s1 == s2;
        
        int cnt = 0;
        int i   = 0; 
        int j   = 0;
        
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++, j++;
            }
            else {
                i++;
            }
            
            if (i == n) {
                i = 0;
                cnt += 1;
            }
            
            if (j == m) return true;
            if (cnt == 2) break;
        }
        return false;
    }
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // return solve_stl(s1, s2);
        
        return solve_iterative(s1, s2);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends