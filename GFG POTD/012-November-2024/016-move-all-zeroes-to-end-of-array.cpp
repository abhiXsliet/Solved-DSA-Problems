// https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    void solve_1(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 1;
        while (j < n) {
            if (arr[i] != 0 && arr[j] != 0) {
                i ++, j ++;
            } else if (arr[i] == 0 && arr[j] != 0) {
                swap(arr[i], arr[j]);
                i ++, j ++;   
            }
            while (j < n && arr[j] == 0) j ++;
            while (i < j && arr[i] != 0) i ++;
        }
    }
    
    // TC : O(N)
    // SC : O(1)
    void solve_2(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 1;
        while (j < n) {
            if (arr[i] == 0 && arr[j] != 0) {
                swap(arr[i], arr[j]);
                i ++, j ++;   
            } else if (arr[i] == 0 && arr[j] == 0) j ++;
            else i ++, j ++;
        }
    }
    
    // TC : O(N)
    // SC : O(1)
    void solve_3(vector<int>& arr) {
        int i = 0;
        for (int j = 0; j < arr.size(); j ++) {
            if (arr[j]) {
                swap(arr[i], arr[j]);
                i ++;
            }
        }
    }
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // solve_1(arr);
        // solve_2(arr);
        solve_3(arr);
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
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends