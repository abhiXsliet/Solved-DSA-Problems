// https://www.geeksforgeeks.org/problems/next-permutation5226/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        
        int idx = -1;
        for (int i = n - 2; i >= 0; i --) {
            if (arr[i] < arr[i + 1]) {
                idx = i;
                break;
            }
        }
        
        if (idx == -1) {
            reverse(begin(arr), end(arr));
            return;
        }

        for (int i = n - 1; i >= idx; i --) {
            if (arr[i] > arr[idx]) {
                swap(arr[i], arr[idx]);
                break;
            }
        }
        
        reverse(begin(arr) + idx + 1, end(arr));
        return;
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
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends