// https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        stringstream ss(str);
        string word;
        int cnt = 0;
        while (getline(ss, word, '.')) {
            if (word.empty() || word.size() > 3) 
                return false;
            
            // Check for leading zeros
            if (word.size() > 1 && word[0] == '0') 
                return false;
            
            int num = stoi(word);
            if (num < 0 || num > 255) 
                return false;
            
            cnt++;
        }
        return cnt == 4;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends