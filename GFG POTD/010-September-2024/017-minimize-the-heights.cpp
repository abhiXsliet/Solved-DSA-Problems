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
        
        int maxi = arr[n - 1];
        int mini = arr[0];
        int maxDiff = maxi - mini;  // initial difference b/w maxium and minimum
        
        int maxEle = 0, minEle = 0; // calculating next maximum and minimum
        
        for (int i = 1; i < n; i ++) {
            if (arr[i] >= k) {
                maxEle  = max(arr[i-1] + k, maxi - k);  // try to reduce maximum
                minEle  = min(arr[i] - k  , mini + k);  // try to increase minimum
                
                maxDiff = min(maxDiff, maxEle - minEle);
            }
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