// https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    vector<int> getNse(vector<int>& arr, int n) {
        vector<int> result(n, n);   // initialized with last index if there's no smaller
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                result[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }        
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> getPse(vector<int>& arr, int n) {
        vector<int> result(n, -1);   // initialized with -1-index if there's no smaller previous elements
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                result[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }        
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& arr, int n) {
        vector<int> nse = getNse(arr, n);
        vector<int> pse = getPse(arr, n);
        
        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            int b = nse[i] - pse[i] - 1;
            int area = arr[i] * b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& arr, int n) {
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                int idx = stk.top();
                stk.pop();

                int nse = i;
                int pse = stk.empty() ? -1 : stk.top();
                
                int b = nse - pse - 1;  // width
                int area = arr[idx] * b;
                maxArea = max(maxArea, area);
            }
            stk.push(i);
        }
        
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            
            int nse = n;
            int pse = stk.empty() ? -1 : stk.top();
            
            int b = nse - pse - 1;
            int area = arr[idx] * b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
  public:
    int getMaxArea(vector<int> &arr) {
        // return approach_1(arr, arr.size());  // THREE - PASS
        return approach_2(arr, arr.size());  // ONE - PASS : While finding NSE, second elements from top of stack will be the PSE
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
// } Driver Code Ends