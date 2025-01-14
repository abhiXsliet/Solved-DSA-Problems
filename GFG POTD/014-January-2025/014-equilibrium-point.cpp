// https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int>& arr) {
        int n = arr.size();
        long total = accumulate(begin(arr), end(arr), 0LL);
        int left   = 0;
        int right  = arr[0] < 0 ? total + abs(arr[0]) : total - arr[0];
        for (int i = 1; i < n; i ++) {
            left += arr[i - 1];
            right = arr[i] < 0 ? right + abs(arr[i]) : right - arr[i];
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        return approach_1(arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends