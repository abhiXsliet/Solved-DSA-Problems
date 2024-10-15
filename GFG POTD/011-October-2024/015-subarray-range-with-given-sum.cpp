// https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        unordered_map<int, int> mpp;    // {cumm_sum, cnt}
        mpp[0]       = 1;
        int cumm_sum = 0;
        int result   = 0;
        
        for (int i = 0; i < n; i ++) {
            cumm_sum += arr[i];
            int diff = cumm_sum - tar;
            if (mpp.count(diff)) {
                result += mpp[diff];
            }
            mpp[cumm_sum] ++;
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends