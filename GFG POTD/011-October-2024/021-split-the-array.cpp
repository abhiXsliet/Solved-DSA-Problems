// https://www.geeksforgeeks.org/problems/split-the-array0238/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int n = arr.size();
        int xorVal = 0;
        for (auto& num : arr) {
            xorVal ^= num;
        }
        
        if (xorVal != 0) return 0;
        
        return (1 << (n - 1)) - 1;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}
// } Driver Code Ends