// https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& arr, int n) {
        unordered_map<int, int> mpp;    // to track the prev sum
        int sum = 0, maxLen = 0;
        mpp[sum] = -1;
        for (int i = 0; i < n; i ++) {
            sum += arr[i] == 0 ? -1 : 1;
            if (mpp.count(sum)) 
                maxLen = max(maxLen, i - mpp[sum]);
            if (!mpp.count(sum)) mpp[sum] = i;
        }
        return maxLen;
    }
  public:
    int maxLen(vector<int> &arr) {
        return approach_1(arr, arr.size()); // find 0 sum by treating 0 as -1
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends