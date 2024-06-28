// https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    bool isPalindrome(vector<int>& row, int n) {
        int i = 0, j = n - 1;
        while (i < j) {
            if (row[i] != row[j]) {
                return false;
            }
            i ++, j --;
        }
        return true;
    }
    
    // TC : O(N^2)
    // SC : O(N)
    string brute(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i = 0; i < n; i ++) {
            if (isPalindrome(mat[i], n)) {
                return to_string(i) + " R";
            }
        } 
        
        for (int j = 0; j < n; j ++) {
            vector<int> temp;
            for (int i = 0; i < n; i ++) {
                temp.push_back(mat[i][j]);
            }
            
            if (isPalindrome(temp, n)) {
                return to_string(j) + " C";
            }
        }
        
        return "-1";
    }
    
    // TC : O(N^2)
    // SC : O(1)
    string better(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i = 0; i < n; i ++) {
            if (isPalindrome(mat[i], n)) {
                return to_string(i) + " R";
            }
        } 
        
        for (int j = 0; j < n; j ++) {
            bool isPalindrome = 1;
            for (int i = 0; i < n/2; i ++) {
                if (mat[i][j] != mat[n - i - 1][j]) {
                    isPalindrome = 0;
                }
            }
            if (isPalindrome) {
                return to_string(j) + " C";
            }
        }
        
        return "-1";
    }
    
    // TC : O(N^2)
    // SC : O(1)
    string optimal(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i = 0; i < n; i ++) {
            bool isPalindrome = 1;
            for (int j = 0; j < n/2; j ++) {
                if (mat[i][j] != mat[i][n - j - 1]) {
                    isPalindrome = 0;
                }
            }
            if (isPalindrome) {
                return to_string(i) + " R";
            }
        } 
        
        for (int j = 0; j < n; j ++) {
            bool isPalindrome = 1;
            for (int i = 0; i < n/2; i ++) {
                if (mat[i][j] != mat[n - i - 1][j]) {
                    isPalindrome = 0;
                }
            }
            if (isPalindrome) {
                return to_string(j) + " C";
            }
        }
        
        return "-1";
    }

    // TC : O(N^2)
    // SC : O(1)
    string optimal_2(vector<vector<int>>& mat) {
        int n = mat.size();
        // store the index of first column palindrome
        int firstColPalindromeIdx = -1; 
        
        for (int i = 0; i < n; i ++) {
            bool isPalindromeRow = 1, isPalindromeCol = 1;
            for (int j = 0; j < n/2; j ++) {
                if (mat[i][j] != mat[i][n - j - 1]) // Check Palindrome : Rows
                    isPalindromeRow = 0;
                    
                if (mat[j][i] != mat[n - j - 1][i]) // Check Palindrome : Cols
                    isPalindromeCol = 0;
            }
            if (isPalindromeRow) 
                return to_string(i) + " R";
            
            if (isPalindromeCol && firstColPalindromeIdx == -1) 
                firstColPalindromeIdx = i;
        } 
        if (firstColPalindromeIdx != -1) 
            return to_string(firstColPalindromeIdx) + " C";
        return "-1";
    }
  public:
    string pattern(vector<vector<int>> &mat) {
        // return brute(mat);
        
        // return better(mat);
        
        // return optimal(mat);     // DOUBLE LOOP
        
        return optimal_2(mat);      // SINGLE LOOP
    }
};


//{ Driver Code Starts.
int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends