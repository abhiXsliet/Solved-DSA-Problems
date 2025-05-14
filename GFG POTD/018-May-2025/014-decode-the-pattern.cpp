// https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    string cntSay(string str) {
        int len = str.length();
        string result;
        int cnt = 0;
        char prev = '$';
        for (int i = 0; i < len; i ++) {
            if (prev == str[i]) {
                cnt += 1;
            } else {
                if (prev != '$') { 
                    result += to_string(cnt);
                    result += prev;
                }
                prev = str[i];
                cnt = 1;
            }
        }
        result += to_string(cnt);
        result += prev;
        return result;
    }
  public:
    // TC : O(2^N)
    // SC : O(2^N)
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string newN = countAndSay(n - 1);
        
        return cntSay(newN);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends