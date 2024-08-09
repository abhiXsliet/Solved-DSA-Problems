// https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    long mod = 1e9 + 7;
    int Maximize(vector<int> &arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        long long int ans = 0;
        for(int i = 0; i < n; i++)
            ans = ((ans) % mod + (1ll * arr[i] * i) % mod) % mod;

        return (int)ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends