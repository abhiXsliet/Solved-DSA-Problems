// https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1




//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    void reverse(string s) {
        int n = s.length(), i = 0, j = n - 1;
        while (i <= j) {
            swap(s[i], s[j]);
            i ++, j --;
        }
    }
    
    string checkCloser(string &s1, string &s2) {
        int m = s1.length();
        string res;
        int carry = 0;
    
        // Subtract each digit starting from the end
        for (int i = 0; i < m; i++) {
            int v1 = s1[m - 1 - i] - '0'; 
            int v2 = s2[m - 1 - i] - '0'; 
    
            int sub = v1 - v2 - carry;
            if (sub < 0) {
                sub += 10; // Borrow from the next digit
                carry = 1; // Set carry for the next iteration
            } else {
                carry = 0; // Reset carry
            }
    
            res += to_string(sub); 
        }
    
        // Remove leading zeros from the result
        while (res.length() > 1 && res.back() == '0') {
            res.pop_back();
        }
    
        reverse(res); 
        return res;
    }
    
    // TC : O(N)
    // SC : O(N)
    string brute(string str) {
        int n = str.length();
        if (str[n - 1] == '0') return str;
        
        string first = str;
        first[n - 1] = '0';
        
        string second = str;
        second[n - 1] = '0';
        
        int carry = 1;
        for (int i = n - 2; i >= 0; i --) {
            int val = second[i] - '0' + carry;
            carry = val / 10;
            val  %= 10;
            second[i] = val + '0';
        }
        if (carry) second = to_string(carry) + second;
        
        // check which is closer first or second
        if (checkCloser(str, first) > checkCloser(second, str)) {
            return second;
        }
        return first;
    }
    
    // TC : O(N)
    // SC : O(1)
    string optimal(string str) {
        int n = str.length();
        if (str[n - 1] >= '0' && str[n - 1] <= '5') {
            str[n - 1]  = '0';
            return str;
        }
        
        str[n - 1] = '0';
        int carry  = 1;
        
        for (int i = n - 2; i >= 0; i --) {
            if (str[i] == '9' && carry) {
                str[i] = '0';
            } else {
                str[i] += carry;
                carry   = 0;
                break;
            }
        }
        if (carry) str = to_string(carry) + str;
        
        return str;
    }
  public:
    string roundToNearest(string str) {
        // return brute(str);  // generate 2-strings and return whoseover is closer to ten
        
        return optimal(str);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends