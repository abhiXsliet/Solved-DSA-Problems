// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-117/problems


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string flipCoins(int N, string s){
        int cntZero = 0;
        for(int i = 0; i < N; i++) {
            if(s[i] == '0') cntZero++;
        }
        
        if(cntZero % 2) return "No";
        else return "Yes";
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int n; 
        cin >> n ; 
        string s; 
        cin >> s; 
        Solution obj;
        string ans = obj.flipCoins(n , s);
        cout << ans << "\n";
    }
}

// } Driver Code Ends