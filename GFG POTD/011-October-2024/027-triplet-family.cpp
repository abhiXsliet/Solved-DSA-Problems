// https://www.geeksforgeeks.org/problems/triplet-family/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N^2)
    // SC : O(1)
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 0; i --) {
            int j = 0, k = i - 1;
            while (j < k) {
                if (arr[i] == arr[j] + arr[k])
                    return true;
                else if (arr[i] > arr[j] + arr[k])
                    j ++;
                else k --;
            }
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
        Solution obj;
        bool res = obj.findTriplet(arr);
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