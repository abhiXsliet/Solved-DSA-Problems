// https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> mpp;  // Stores the first occurrence of each sum
        int sum = 0, len = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += (arr[i] > k) ? 1 : -1;
            
            if (sum > 0) {
                len = max(len, i + 1);  // Entire subarray from 0 to i is valid
            } else if (mpp.count(sum - 1)) {
                len = max(len, i - mpp[sum - 1]);  // Subarray where sum > 0
            }
            
            if (!mpp.count(sum)) {
                mpp[sum] = i;  // Store the first occurrence of sum
            }
        }
        
        return len;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends