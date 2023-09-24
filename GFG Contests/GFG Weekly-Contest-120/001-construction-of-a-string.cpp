// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-120-1628/problems



//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string construct(int N,int K) {
        vector<char> arr(N, -1);
        
        bool flag = 1;
        for (int i = 0; i < N-K+1; i++) {
            if(flag) {
                if(arr[i+K-1] == -1) arr[i+K-1] = 'a';
                if(arr[i+K-2] == -1) arr[i+K-2] = 'b';
            }
            else {
                if(arr[i+K-1] == -1) arr[i+K-1] = 'b';
                if(arr[i+K-2] == -1) arr[i+K-2] = 'a';
            }
            flag = !flag;
        }
        
        for (int i = 0; i < N; i++) {
            if (arr[i] == -1)
                arr[i] = 'z';
        }
                
        string str = "";
        for (int i = 0; i < N; i++) {
            str += arr[i];
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution obj;
        auto ans = obj.construct(N,K);
        int ok=1;
        if(ans.size()!=N)
        ok=0;
        int lastVowel=-1,lastConsonant=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]<'a'||ans[i]>'z')
                ok=0;
            if(ans[i]=='a'||ans[i]=='e'||ans[i]=='i'||ans[i]=='o'||ans[i]=='u')
                lastVowel=i;
            else 
                lastConsonant=i;
            if(i>=K-1){
                if(lastVowel>=i-K+1&&lastConsonant>=i-K+1);
                else
                    ok=0;
            }
        }
        if(ok)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
} 
// } Driver Code Ends