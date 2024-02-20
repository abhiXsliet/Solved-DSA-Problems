// https://www.geeksforgeeks.org/problems/word-break1352/1



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
private:
    // TC = O(2^N)
    // SC = O(N)
    bool solve_rec(string s, unordered_set<string>& st, int index) {
        if(index == s.size()) return 1;

        for(int i = index; i < s.size(); i++) {
            if(st.count(s.substr(index, i+1-index)) && solve_rec(s, st, i+1)) {
                return 1;
            }
        }
        return 0;
    }

    // TC = O(N^3)
    // SC = O(N)
    bool solveMem(string s, unordered_set<string>& st, int index, vector<int>& dp) {
        if(index == s.size()) return 1;

        if(dp[index] != -1) return dp[index];

        for(int i = index; i < s.size(); i++) {
            if(st.count(s.substr(index, i+1-index)) && solveMem(s, st, i+1, dp)) {
                return 1;
            }
        }
        return dp[index] = 0;
    }

    // TC = O(N^3)
    // SC = O(N)
    bool solveTab(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        // Analyze the base case
        dp[0] = 1;
                
        unordered_set<string> st;
        for(auto i : wordDict) st.insert(i);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && st.count(s.substr(j, i-j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
public:
    int wordBreak(int n, string A, vector<string> &B) {
        unordered_set<string> st;
        
        for (auto& str : B) st.insert(str);
        
        // return solve_rec(A, st, 0);
        
        // vector<int> dp(A.size()+1, -1);
        // return solveMem(A, st, 0, dp);
        
        return solveTab(A, B);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends