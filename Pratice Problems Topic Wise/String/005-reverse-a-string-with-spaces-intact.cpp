// https://practice.geeksforgeeks.org/problems/reverse-a-string-with-spaces-intact5213/1?



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
  
        string reverseWithSpacesIntact (string s)
        {
            int i = 0;
            int j = s.length() - 1;
            while(i <= j) {
                if(s[i] == ' ' && s[j] == ' ') {
                    i++, j--;
                } else if(s[i] == ' ') {
                    i++;
                } else if(s[j] == ' ') {
                    j--;
                }else{
                    
                    // swap(s[i++], s[j--]);

                    char ch = s[i];
                    s[i] = s[j];
                    s[j] = ch;
                    i++, j--;
                }
            }
            return s;
        }
      

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout << ob.reverseWithSpacesIntact (s) << endl;
    }
    return 0;
}
// Contributed By: Pranay Bansal

// } Driver Code Ends