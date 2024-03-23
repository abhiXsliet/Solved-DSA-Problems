// https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    int fib(int n) {
        if (n <= 0 || n == 1) return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b; 
            b = c;
        }
        return b;
    }
    
    // TC : O(N^2)
    // SC : O(1) but O(N) to return ans
    vector<int> solve_basic(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(fib(i));
        }
        return res;
    }
    
    // TC : O(N)
    // SC : O(1) but O(N) to return ans
    vector<int> solve_better(int n) {
        vector<int> res(n+1, 0);
        res[1] = 1;
        for (int i = 2; i <= n; i++) {
            res[i] = (res[i - 1] + res[i - 2]) % 1000000007;
        }
        return res;
    }
  public:
    vector<int> Series(int n) {
        // return solve_basic(n);
        
        return solve_better(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends