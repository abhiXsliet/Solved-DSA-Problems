// https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // TC : O(n * min(|arri|))
    // SC : O(min(|arri|))
    string longestCommonPrefix(vector<string> arr) {
        int N = arr.size();
        string ans;
        for (int i = 0; i < arr[0].length(); i++) {
            for (int j = 1; j < N; j++) {
                if (arr[0][i] != arr[j][i])
                    return ans.length() == 0 ? "-1" : ans;
            }
            ans += arr[0][i];
        }
        return ans.length() == 0 ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}
// } Driver Code Ends