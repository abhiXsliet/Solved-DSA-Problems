// https://www.geeksforgeeks.org/problems/implement-atoi/1



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  private:
    // TC : O(N)
    // SC : O(1)
    int brute(string& s, int n) {
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0 && s[i] == '-') continue;
            if (s[i] >= '0' && s[i] <= '9') continue;
            else {
                flag = 0; 
                break;
            }
        }
        
        if (flag) return stoi(s);
        else return -1;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(string& s, int n) {
        int ans = 0;
        int i;
        int sign = 1;
        
        if (s[0] == '-' ? i = 1 : i = 0);
        if (s[0] == '-') sign = -1;
        
        for (; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + s[i] - '0';
            }
            else return -1;
        }
        
        return (int)(ans * sign);
    }
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        // return brute(s, s.length());
        
        return optimal(s, s.length());
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends