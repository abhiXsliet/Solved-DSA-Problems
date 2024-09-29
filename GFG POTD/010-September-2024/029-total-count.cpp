// https://www.geeksforgeeks.org/problems/total-count2415/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; i ++) {
            double val = (double)arr[i] / (double)k;
            res += ceil(val);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.totalCount(k, arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends