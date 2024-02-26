// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-143/problems



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string smallestString(int n, string s) {
        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a';
            if ((i != n-1 && val == 0) || (n % 2 == 1 && i == n/2)) continue;
            else {
                if (i != n - 1) {
                    int v = s[i] - 'a';
                    if (v != 0) {
                        v = v - 1;
                        s[i] = char(0 + 'a');
                        return s;
                    }
                    else continue;
                }
                else {
                    int value = s[i] - 'a';
                    if (value != 0) {
                        value = value - 1;
                        s[i] = char(value + 'a');
                        return s;
                    }
                    else if (value == 0) {
                        value += 1;
                        s[i] = char(value + 'a');
                        return s;
                    }
                }
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        string s;
        cin>>s;
        
        Solution obj;
        string res = obj.smallestString(n, s);
        
        cout<<res<<"\n";
        
    }
}

// } Driver Code Ends