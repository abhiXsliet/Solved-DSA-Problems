// https://www.geeksforgeeks.org/problems/powx-n/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(log(e))
    // SC : O(1)
    double approach_1(double b, int e) {
        if (e == 0) return 1.0;
        int originalE = e;
        if (e  < 0) e = -e;
        
        double ans = 1;
        while (e) {
            if (e % 2) {
                ans *= b;
                e --;    // can be remove since managed by e/=2
            }
            e /= 2;
            b *= b;
        }
        if (originalE < 0) return double(1 / ans);
        return ans;
    }
    
    double solve(double b, int e) {
        if (e == 0) return 1.0;
        
        if (e % 2) {
            return solve(b, e - 1) * b;
        }
        return solve(b * b, e / 2);
    }
    
    // TC : O(log(e))
    // SC : O(log(e)) Recursive Depth
    double approach_2(double b, int e) {
        if (e == 0) return 1.0;
        int originalE = e;
        if (e  < 0) e = -e;
        
        double ans = solve(b, e);
        
        if (originalE < 0) return double(1 / ans);
        return ans;
    }
  public:
    double power(double b, int e) {
        // return approach_1(b, e);    // Iterative
        
        return approach_2(b, e);    // Recursive
    }
};


//{ Driver Code Starts.
int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends