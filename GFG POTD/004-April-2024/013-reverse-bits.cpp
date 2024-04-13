// https://www.geeksforgeeks.org/problems/reverse-bits3556/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    // TC : O(log(n))
    // SC : O(1)
    long long solve_1(long long x) {
        long long ans = 0;
        int i = 31;
        while(x) {
            ans += (long long)pow(2, i) * (x & 1);
            i --;
            x >>= 1;
        }
        return ans;
    }
    
    // TC : O(log(n))
    // SC : O(1)
    long long solve_2(long long x) {
        long long ans = 0;
        int i = 31;
        while(x) {
            ans += (long long)pow(2, i) * (x % 2);
            i --;
            x /= 2;
        }
        return ans;
    }
  public:
    long long reversedBits(long long x) {
        // return solve_1(x);
        
        return solve_2(x);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends