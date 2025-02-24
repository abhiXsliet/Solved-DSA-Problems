// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[i] > arr[stk.top()]) {
                result[stk.top()] = stk.top() - i;
                stk.pop();
            }
            stk.push(i);
        }
        // handles all the decreasing values from right to left
        while (!stk.empty()) {
            result[stk.top()] = stk.top() + 1;
            stk.pop();
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends