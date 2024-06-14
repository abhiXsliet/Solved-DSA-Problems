// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    string way_1(int n) {
        string s = to_string(n);
        int len  = s.length();
        
        int ans = 0;
        for (int i = 0; i < len; i ++) {    // O(4)
            int val = s[i] - '0';
            ans    += pow(val, 3);
        }

        return ans == n ? "true" : "false";
    }
    
    string way_2(int n) {
        int temp = n;
        int ans = 0;
        while (n > 0) {
            int val = n % 10;
            ans += pow(val, 3);
            n /= 10;
        }
        return ans == temp ? "true" : "false";
    }
  public:
    string armstrongNumber(int n) {
        // return way_1(n);
        
        return way_2(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}
// } Driver Code Ends