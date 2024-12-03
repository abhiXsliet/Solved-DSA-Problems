// https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1




//{ Driver Code Starts
/* Driver program to test above function */
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
private:
    bool ispalindrome(string s) {
        int l = s.length();
        int j;
         
        for(int i = 0, j = l - 1; i <= j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute(string& s, int n) {
        int cnt  = 0;
        int flag = 0;
        while(n > 0) {
            // if string becomes palindrome then break
            if(ispalindrome(s)) {
                flag = 1;
                break;
            }
            else {
                cnt++;
                // erase the last element of the string
                s.erase(s.begin() + s.length() - 1);
            }
        }
         
        // print the number of insertion at front
        if(flag)
            return cnt;
        return -1;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int solve_better(string& s, int n) {
        int i = 0;
        int j = s.length() - 1;
        int trim = j;
        int res = 0;
    
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                i  = 0;
                trim --;
                j = trim;
                res ++;
            }
        }
        return res;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> find_lps(string& s, int n) {
        vector<int> result(n, 0);
        for (int i = 1; i < n; i++) {
            int j = result[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = result[j - 1];
            }
            
            if (s[i] == s[j]) j++;
            result[i] = j;
        }
        return result;
    }
    
    vector<int> z_function(string& str, int n) {
        vector<int> z(n, 0);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            // if i is in the range of l and r 
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            
            while (i + z[i] < n && str[z[i]] == str[i + z[i]])
                z[i]++;
                
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
    
    // TC : O(N + M)
    // SC : O(N + M) Where N = string length & M = reversed string length
    // USING KMP-ALGO
    int solve_optimal_1(string& str, int n) {
        string rev = str;
        reverse(begin(rev), end(rev));
        
        string newStr = str + '$' + rev;
        
        vector<int> lps = find_lps(newStr, newStr.length());
        int idx = lps.size() - 1;
        
        if (n - lps[idx] < 0) return 1;
        return (n - lps[idx]);
    }
    
    // TC : O(N + M)
    // SC : O(N + M) Where N = string length & M = reversed string length
    // USING KMP-ALGO
    int solve_optimal_2(string& str, int n) {
        string rev = str;
        reverse(begin(rev), end(rev));
        
        string newStr = str + '$' + rev;
        
        vector<int> Z = z_function(newStr, newStr.length());
        
        int charRemove = 0;
        for (int i = 0; i < Z.size(); i++) {
            if (Z[i] == newStr.length() - i) {
                charRemove = max(charRemove, Z[i]);
            }
        }
        return n - charRemove;
    }
public:
    int minChar(string str){
        // return solve_brute(str, str.length());
        
        // return solve_better(str, str.length());
        
        return solve_optimal_1(str, str.length());
        
        // return solve_optimal_2(str, str.length());
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
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends