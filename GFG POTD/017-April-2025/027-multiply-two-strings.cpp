// https://www.geeksforgeeks.org/problems/multiply-two-strings/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(M * N)
    // SC : O(M * N)
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        if (s1 == "0" || s2 == "0")
            return "0";
            
        bool isNegative = false;
        if (s1[0] == '-' && s2[0] == '-') {
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        } else if (s1[0] == '-') {
            isNegative = true;
            s1 = s1.substr(1);
        } else if (s2[0] == '-') {
            isNegative = true;
            s2 = s2.substr(1);
        }
        
        int m = s1.length(), n = s2.length();
        vector<int> store(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (s1[i] - '0') * (s2[j] - '0');
                int sum = product + store[i + j + 1];
                store[i + j + 1] = sum % 10;
                store[i + j] += sum / 10;
            }
        }
        
        string res;
        for (int num : store) {
            if (!(res.empty() && num == 0)) { // Skip leading zeros
                res += to_string(num);
            }
        }
        
        if (res.empty()) return "0"; // Handle case where result is zero
        if (isNegative) res = "-" + res;
        return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends