// https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(string &s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int i = 0, j = 0, result = 0;
        while (j < n) {
            freq[s[j] - 'a'] ++;
            while (i < j && freq[s[j] - 'a'] > 1) {
                freq[s[i] - 'a'] --;
                i ++;
            }
            result = max(result, j - i + 1);
            j ++;
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(string &s) {
        int n = s.length();
        int mask = 0;
        int i = 0, j = 0, result = 0;
        while (j < n) {
            int pos = s[j] - 'a';
            // Check if the ith bit is set or not ? 
            // If the bit is set, it means the character is repeated
            if (mask & (1 << pos)) {
                // Move i forward until the repeated character is removed 
                while (i < j && (mask & (1 << pos))) {
                    mask &= ~(1 << s[i] - 'a');
                    i ++;
                }
            }
            
            // set the bit for the current char
            mask |= (1 << pos);
            
            result = max(result, j - i + 1);
            j ++;
        }
        return result;
    }
  public:
    int longestUniqueSubstr(string &s) {
        // return approach_1(s);    // Using freq array
        
        return approach_2(s);   // using bit
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends