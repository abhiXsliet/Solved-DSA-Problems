// https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(M)
    // SC : O(M)
    vector<int> getLPS(string& s) {
        int m = s.length();
        vector<int> LPS(m, 0);
        
        for (int i = 1; i < m; i++) {
            int j = LPS[i - 1];
            
            while (j > 0 && s[i] != s[j])
                j = LPS[j - 1];
            
            if (s[i] == s[j]) j ++;
            LPS[i] = j;
        }
        
        return LPS;
    }  

    // TC : O(M^2)
    // SC : O(1)
    bool brute(string& s1, string& s2) {
        int m = s1.length();
        for (int i = 0; i < m; i ++) {
            if (s1 == s2) return true;
            // char temp = s1[0];
            // s1.erase(0, 1);
            // s1 += temp;
            
            rotate(s1.begin(), s1.begin() + 1, s1.end());
        }
        return false;
    }
    
    // TC : O(M^2)
    // SC : O(1)
    bool better(string& s1, string& s2) {
        s1 = s1 + s1;
        if (s1.find(s2) != string::npos) 
            return true;
        return false;
    }
    
    // TC : O(M + N)
    // SC : O(M)
    bool optimal(string& s1, string& s2) {
        s1 = s1 + s1;
        int m = s1.length(), n = s2.length();
        
        vector<int> LPS = getLPS(s2);
        
        int i = 0, j = 0;
        while (i < m) {
            if (s1[i] == s2[j]) {
                i ++, j ++;
            } else {
                if (j > 0) j = LPS[j - 1];
                else i ++;
            }
            if (j == n) return true;
        }
        return false;
    }
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // return brute(s1, s2);   // shift one by one char and check both strings
        
        // return better(s1, s2);  // concat s1 + s1 and check if s1 == s2
        
        return optimal(s1, s2); // KMP
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends