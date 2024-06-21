// https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1




//{ Driver Code Starts
#include <iostream>
#include <regex>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(|len of Str|)
    // SC : O(1)
    string way_1(string str) {
        stringstream ss(str);
        string fraction;
        string maxStr;
        double maxVal = 0;
        
        while (getline(ss, fraction, ',')) {
            stringstream fractionStr(fraction);
            string numerator  ;
            string denominator;
            
            getline(fractionStr, numerator  , '/');
            getline(fractionStr, denominator, '/');
            
            double numer   = stod(numerator);
            double denom   = stod(denominator);
            double currVal =  numer / denom;

            if (currVal > maxVal) {
                maxVal = currVal;
                maxStr = fraction;
            } else if (currVal == maxVal) {
                return "equal";
            }
        }
        
        return maxStr[0] == ' ' ? maxStr.erase(0, 1) : maxStr; 
    }
  public:
    string compareFrac(string str) {
        return way_1(str);
    }
};


//{ Driver Code Starts.
int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}
// } Driver Code Ends