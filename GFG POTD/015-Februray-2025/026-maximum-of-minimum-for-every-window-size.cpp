// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N^3)
    // SC : O(1)
    vector<int> brute(vector<int>& arr, int n) {
        vector<int> result(n, 0);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n - i; j ++) {  
                int num = INT_MAX;
                for (int k = j; k < i + j + 1; k ++) {
                    num = min(num, arr[k]);
                }
                result[i] = max(result[i], num);
            }
        }
        return result;
    }

    // TC : O(N^2)
    // SC : O(1)
    vector<int> better(vector<int>& arr, int n) {
        vector<int> result(n, 0);
        for (int i = 0; i < n; i ++) {
            int num = INT_MAX;
            for (int j = i; j < n; j ++) {  
                num = min(num, arr[j]);
                result[j - i] = max(result[j - i], num);
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    // Optimization: For each element, find the range [i, j] where the element is the minimum within that range (e.g., [2, 5] where the element is the minimum from 2 to 5). 
    // Place the element at the last index of its range. 
    // Finally, compute the prefix maximum starting from the end.
    vector<int> optimal(vector<int>& arr, int n) {
        vector<int> result(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                int nse = i;
                int currEleIdx = stk.top();
                stk.pop();
                
                int pse = stk.empty() ? -1 : stk.top();
                int range = nse - pse - 1;      // {1, range}
                int rangeEndIdx = range - 1;    // 0 - based indexing
                
                result[rangeEndIdx] = max(result[rangeEndIdx], arr[currEleIdx]);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int nse = n;
            int currEleIdx = stk.top();
            stk.pop();
            
            int pse = stk.empty() ? -1 : stk.top();
            int range = nse - pse - 1;
            int rangeEndIdx = range - 1;

            result[rangeEndIdx] = max(result[rangeEndIdx], arr[currEleIdx]); 
        }
        
        // update the result with the max value from the left
        for (int i = n - 2; i >= 0; i --) {
            result[i] = max(result[i], result[i + 1]);
        }
        return result;
    }
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // return brute(arr, arr.size());
        // return better(arr, arr.size());
        return optimal(arr, arr.size());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends