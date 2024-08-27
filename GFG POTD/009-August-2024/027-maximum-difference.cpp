// https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    void fillLeftSmaller(vector<int>& arr, int n, vector<int>& leftSmaller) {
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && stk.top() >= arr[i]) // catch : missed =
                stk.pop();
                
            if (!stk.empty()) {
                leftSmaller[i] = stk.top();
            } else {
                leftSmaller[i] = 0;
            }
            stk.push(arr[i]);
        }
    }
    
    void fillRightSmaller(vector<int>& arr, int n, vector<int>& rightSmaller) {
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && stk.top() >= arr[i])     // catch : missed =
                stk.pop();
                
            if (!stk.empty()) {
                rightSmaller[i] = stk.top();
            } else {
                rightSmaller[i] = 0;
            }
            stk.push(arr[i]);
        }
    }
  public:
    // TC : O(N)
    // SC : O(N)
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> leftSmaller(n, 0);
        vector<int> rightSmaller(n, 0);
        
        fillLeftSmaller(arr, n, leftSmaller);
        fillRightSmaller(arr, n, rightSmaller);
        
        int maxDiff = 0;
        for (int i = 0; i < n; i ++) {
            maxDiff = max(maxDiff, abs(leftSmaller[i] - rightSmaller[i]));
        }
        return maxDiff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends