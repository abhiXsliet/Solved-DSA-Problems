// https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1



//{ Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function template for C++
class Solution{
  private:
    // TC : O(N^2)
    // SC : O(N)
    int solveSO(string& A, string& B) {
        int n = A.length();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = INT_MIN;
                if(A[i] == B[j]) {
                    ans = 1 + next[j+1];
                } else {
                    ans = max(curr[j+1], next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    
    int longestPalinSubseq(string A) {
        string B = A;
        reverse(B.begin(), B.end());
        
        return solveSO(A, B);
    }
  public:
    int countMin(string str){
        return str.length() - longestPalinSubseq(str);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}
// } Driver Code Ends