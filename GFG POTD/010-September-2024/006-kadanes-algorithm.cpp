// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int sum  = 0;
        int maxS = INT_MIN;
        
        for (int i = 0; i < n; i ++) {
            sum += arr[i];
            maxS = max(maxS, sum);
            if (sum < 0) sum = 0;
        }
        
        return maxS;
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
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends