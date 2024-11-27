// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int brute(vector<int>& arr) {
        unordered_set<int> st(begin(arr), end(arr));
        for (int i = 1; i <= 1e5; i ++) {
            if (!st.count(i)) {
                return i;
            }
        }
        return -1;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            if (arr[i] > 0 && arr[i] <= n) {
                if (arr[i] != arr[arr[i] - 1]) {
                    swap(arr[i], arr[arr[i] - 1]);
                    i --;   
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            if (arr[i] - 1 != i) {
                return i + 1;
            }
        }
        return n + 1;
    }
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // return brute(arr);   // using set
        
        return optimal(arr); // swap element at its correct postion
    }
};


//{ Driver Code Starts.
// int missingNumber(int arr[], int n);
int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends