// https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        
        int maxi = arr[n - 1];
        int mini = arr[0];
        int maxDiff = maxi - mini;
        
        int maxEle = 0, minEle = 0;
        
        for (int i = 1; i < n; i ++) {
                maxEle  = max(arr[i-1] + k, maxi - k);  // try to reduce maximum
                minEle  = min(arr[i] - k  , mini + k);  // try to increase minimum
                maxDiff = min(maxDiff, maxEle - minEle);
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
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends