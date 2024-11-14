// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= k; i ++) {
            pq.push(arr[i]);
        }
        
        int idx = 0;
        for (int i = k + 1; i < n; i ++) {
            arr[idx ++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while (!pq.empty()) {
            arr[idx ++] = pq.top();
            pq.pop();
        }
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
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends