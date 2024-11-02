// https://www.geeksforgeeks.org/problems/kth-distance3757/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // TC : O(N)
    // SC : O(K)
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        while (j < n) {
            mpp[arr[j]] ++;
            if (mpp[arr[j]] == 2) {
                return true;
            }
            if (j - i == k) {
                mpp[arr[i]] --;
                if (mpp[arr[i]] == 0) 
                    mpp.erase(arr[i]);
                i ++;
            }
            j ++;
        }
        return false;
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
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends