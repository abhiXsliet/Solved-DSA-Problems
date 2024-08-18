// https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum = accumulate(begin(arr), end(arr), 0);
        int val = 0;
        for (int i = 0; i < arr.size(); i ++) {
            val += arr[i];
            if (val == sum - val)
                return true;
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends