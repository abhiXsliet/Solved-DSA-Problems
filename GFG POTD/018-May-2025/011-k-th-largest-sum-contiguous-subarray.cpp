// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(N^2 * log(K))
    // SC : O(log(K))
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < n; i ++) {
            int sum = 0;
            for (int j = i; j < n; j ++) {
                sum += arr[j];

                if (pq.size() < k) {
                    pq.push(sum);
                } else if (pq.top() < sum) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        return pq.top();
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
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends