// https://www.geeksforgeeks.org/problems/magical-box5306/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double P, double A) {
        // V = lbh put bh = A/2 - (lb + lh) from area
        // V = l(A/2 - l(b + h)) now put (b + h) from perimeter (i.e, (b+h) = P/4 - l)
        // V = l(A/2 - l(P/4 - l)) = A/2*l - P/4*l^2 + l^3
        
        // Now Differentiate w.r.t l (dv/dl) : A/2 - 2*P/4*l + 3*l^2 
        // => dv/dl = 3*l^2 - P/2*l + A/2 (Quadratic Eqn)
        // l = (b - sqrt(b^2 - 4ac)) / 2*a where a = 3, b = -P/2, c = A/2
        // l = (P - sqrt(P^2 - 24*A)) / 12 ------> eq.I
        // So, V = lbh to maximize vol. consider b = l V = l*l*h where 
        // h = P/4 - 2l since b = l ------> eq.II
        // From eq.I and eq.II you'll get the answer
        
        double l = (P - sqrt(P*P - 24*A)) / 12;   // from eq.I
        
        double h = (P/4 - 2*l);                   // from eq.II
        
        double V = (l*l*(h));  // V = l*b*h but to maximize V consider b = l
                               // V = l*l*h where h = P/4 - 2*l 
        return V;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends