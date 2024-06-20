// https://www.geeksforgeeks.org/problems/integral-points-in-triangle5026/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    typedef long long int ll;
    
    ll gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    
    ll getBoundary(ll p[], ll q[]) {
        return gcd( abs(p[0] - q[0]), abs(p[1] - q[1]) );
    }
  public:
    // TC : O(log(10^18))
    // SC : O(1)
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
                                    
        // PICK THEOREM : A = I + B/2 - 1 => I = (2*A - B + 2) / 2
        
        // calculate the no. of boundary points
        ll boundaryPoints = getBoundary(p, q) + getBoundary(p, r) + 
                            getBoundary(q, r);
        
        // calculate double Area of triangle
        // since Area of Triangle = abs(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2
        ll doubleArea = abs( p[0]*(q[1] - r[1]) + q[0]*(r[1] - p[1]) + 
                             r[0]*(p[1] - q[1]) );
                              
        // Using Pick Theorm : return no. of Interior points 
        return (doubleArea - boundaryPoints + 2) / 2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends