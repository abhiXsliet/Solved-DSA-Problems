// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int cumm_xor = 0;
        long cntSubarrays = 0;
        for (int i = 0; i < n; i ++) {
            cumm_xor ^= arr[i];
            cntSubarrays += mpp[cumm_xor ^ k];  // is there an x available? (x = cumm_xor ^ k)
            mpp[cumm_xor] ++;
        }
        return cntSubarrays;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends