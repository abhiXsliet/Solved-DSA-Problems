// https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution { 
  private:
    // TC : O(log(N))
    // SC : O(1)
    int binarySearch(int low, int high, int tar, vector<int>& arr) {
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= tar) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<int>& arr, int target) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int cntPairs = 0;
        for (int i = 0; i < n; i ++) {
            int tar = target - (arr[i] + 1);
            int idx = binarySearch(i + 1, n - 1, tar, arr);
            cntPairs += (idx == 0 ? 0 : idx - i);
        }
        return cntPairs;
    }
  public:
    int countPairs(vector<int> &arr, int target) {
        return approach_1(arr, target);
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends