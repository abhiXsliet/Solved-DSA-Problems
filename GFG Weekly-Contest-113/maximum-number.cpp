// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-113/problems



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int maximumNumber(int N) {
        string numStr = to_string(N);
        int n = numStr.length();
        for (int i = 0; i < n; i++) {
            if (numStr[i] == '7') {
                numStr[i] = '9';
                break;
            }
        }

        return stoi(numStr);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        Solution obj;
        int res = obj.maximumNumber(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends