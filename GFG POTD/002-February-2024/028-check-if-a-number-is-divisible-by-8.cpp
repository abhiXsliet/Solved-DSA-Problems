// https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1



//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.length();
        if (n < 3) {
            int val = stoi(s);
            if (val % 8 == 0) 
                return 1;
            return -1;
        }
        
        // Check if the last three digits are divisible by 8 or not?
        string last_three_chars = s.substr(n-3, 3);
        int last_three_digits   = stoi(last_three_chars);
        if (last_three_digits % 8 == 0)
            return 1;
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends