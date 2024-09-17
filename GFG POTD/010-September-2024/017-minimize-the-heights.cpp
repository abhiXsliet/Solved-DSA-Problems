// https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        
        int mini    = arr[0];
        int maxi    = arr[n - 1];
        int minDiff = maxi - mini;

        for (int i = 1; i < n - 1; i ++) {
            if (arr[i] >= k) {  
                int maxEl = max(arr[i - 1] + k, maxi - k);
                int minEl = min(arr[i] - k, mini + k);
                
                minDiff = min(minDiff, maxEl - minEl);
            }
        }
        return minDiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends