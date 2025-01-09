// https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int i = 0, j = i;
        int cumm_sum = 0;
        while (j < n) {
            cumm_sum += arr[j];
            while (i < j && cumm_sum > target) {
                cumm_sum -= arr[i];
                i ++;
            }
            if (cumm_sum == target) {
                return {i + 1, j + 1};
            }
            j ++;
        }
        return {-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends