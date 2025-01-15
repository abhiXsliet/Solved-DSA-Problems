// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    // This codes is optimal for negatives, positives and zeros
    // But can be optimized using 2-ptr only if array has positives and zeros
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0, prefSum = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i ++) {
            prefSum += arr[i];
            if (prefSum == k) 
                maxLen = max(maxLen, i + 1);
            if (mpp.count(prefSum - k)) 
                maxLen = max(maxLen, i - mpp[prefSum - k]);
            if (!mpp.count(prefSum)) 
                mpp[prefSum] = i;
        }
        return maxLen;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends