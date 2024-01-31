// https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1



//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  private:
    bool isChar(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            return 1;
        return 0;
    }
  public:
    // TC : O(N)
    // SC : O(1)
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        unordered_set<char> st;
        for (char& ch : s) {
            if (isChar(ch)) {
                ch = tolower(ch);
                st.insert(ch);
            }
        }
        return st.size() == 26;
    }
};


//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends