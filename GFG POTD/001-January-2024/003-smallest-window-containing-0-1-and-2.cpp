// https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    // TWO POINTER APPROACH
    int solve_approach_1(string& s, int n) {
        vector<int> freq(3, 0);
        
        int ans   = INT_MAX;
        int left  = 0;
        int right = 0;
        bool flag = 0;
        
        while (right < n || left < right) {
            if (!flag && right < n) {
                freq[s[right++] - '0']++;
                
                if (freq[0] && freq[1] && freq[2]) {
                    flag = 1;
                }
                else {
                    flag = 0;
                }
            }
            else if (left < right) {
                freq[s[left++] - '0']--;
                
                if (freq[0] && freq[1] && freq[2]) {
                    flag = 1;
                }
                else {
                    flag = 0;
                }
            }
            
            if (flag) {
                ans = min(ans, right - left);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_approach_2(string& s, int n) {
        
        int x = -1, y = -1, z = -1;
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') 
                x = i;
            else if (s[i] == '0') 
                y = i;
            else if (s[i] == '2')
                z = i;
                
            if (x == -1 || y == -1 || z == -1)
                continue;
                
            int maxLength = max({x, y, z});
            int minLength = min({x, y, z});
            
            ans = min(ans, maxLength - minLength + 1);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
  public:
    int smallestSubstring(string S) {
        // return solve_approach_1(S, S.length());
        
        return solve_approach_2(S, S.length());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends