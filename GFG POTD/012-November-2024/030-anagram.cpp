// https://geeksforgeeks.org/problems/anagram-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(M * log(M)) + O(N * log(N))
    // SC : O(1)
    bool approach_1(string& s1, string& s2) {
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        return s1 == s2;
    }
    
    // TC : O(M + N)
    // SC : O(1)
    bool approach_2(string& s1, string& s2) {
        vector<int> store(26, 0);
        for (char& ch : s1) store[ch - 'a'] ++;
        for (char& ch : s2) store[ch - 'a'] --;
        for (int &v : store) if (v != 0) return false;
        return true;
    }
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // return approach_1(s1, s2);
        
        return approach_2(s1, s2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends