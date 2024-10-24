// https://www.geeksforgeeks.org/problems/ease-the-array0633/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> res;
        int cntZero = 0;
        for (int i = 1; i < n; i ++) {
            if (arr[i] != 0 && arr[i] == arr[i - 1]) {
                cntZero ++;
                res.push_back(arr[i] * 2);
                i ++;
            } else {
                if (arr[i - 1] != 0) { 
                    res.push_back(arr[i - 1]);
                } else {
                    cntZero ++;
                }
                
                if (i + 1 == n && arr[i] != 0) {
                    res.push_back(arr[i]);
                } else if (i + 1 == n) {
                    cntZero ++;
                }
            }
        }
        while(cntZero --) {
            res.push_back(0);
        }
        return res;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends