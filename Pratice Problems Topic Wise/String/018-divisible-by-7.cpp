// https://www.geeksforgeeks.org/problems/divisible-by-73224/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // TC : O(N)
    int isdivisible7(string num){
        int res = 0;
        for (int i = 0; i < num.size(); i++) {
            res = ((res * 10) + (num[i] - '0'));
            res %= 7;
        }
        if (res%7) return 0;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isdivisible7(s) << endl;
    }
    return 0;
}
// } Driver Code Ends