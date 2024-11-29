// https://www.geeksforgeeks.org/problems/add-binary-strings3805/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:  
    // TC : O(M + N) Where M = s1.length() & N = s2.length()
    // SC : O(M + N) 
    string brute(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        int i = m - 1, j = n - 1;
        int carry = 0;
        string res;
        while (i >= 0 && j >= 0) {
            int sum = (s1[i] - '0') + (s2[j] - '0');
            if (carry) sum += carry;
            
            if (sum >= 2) carry = 1;
            else carry = 0;
            
            if (sum % 2) {
                res += '1';
            } else {
                res += '0';
            }
            i --, j --;
        }
        while (i >= 0) {
            int sum = (s1[i] - '0') + carry; 
            
            if (sum >= 2) carry = 1;
            else carry = 0;
            
            if (sum % 2) {
                res += '1';
            } else {
                res += '0';
            }
            i --;
        }
        while (j >= 0) {
            int sum = (s2[j] - '0') + carry; 
           
            if (sum >= 2) carry = 1;
            else carry = 0;
            
            if (sum % 2) {
                res += '1';
            } else {
                res += '0';
            }
            j --;
        }
        if (carry) res = res + "1";
        reverse(begin(res), end(res));
        res.erase(begin(res), begin(res) + res.find_first_not_of('0'));
        return res;
    }
    
    // TC : O(M + N)
    // SC : O(M + N)
    string optimal(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        int i = m - 1, j = n - 1;
        string res;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i] - '0';
            if (j >= 0) sum += s2[j] - '0';
            
            carry = sum / 2;
            
            res += (sum % 2) + '0';
            
            i --, j --;
        }
        reverse(begin(res), end(res));
        res.erase(begin(res), begin(res) + res.find_first_not_of('0'));
        return res;
    }
  public:
    string addBinary(string& s1, string& s2) {
        // return brute(s1, s2);   
        
        return optimal(s1, s2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends