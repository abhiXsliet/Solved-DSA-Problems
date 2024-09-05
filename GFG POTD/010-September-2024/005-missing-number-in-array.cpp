// https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    int approach_1(int n, vector<int>& arr) {
        sort(begin(arr), end(arr));
        for (int i = 0; i < n; i ++) {
            if (i + 1 != arr[i]) {
                return (i + 1);
            }
        }
        return n;
    }
    
    int approach_2(int n, vector<int>& arr) {
        int wholeSum = (n * (n + 1)) / 2;
        int totalSum = accumulate(begin(arr), end(arr), 0);
        return wholeSum - totalSum;
    }
    
    int approach_3(int n, vector<int>& arr) {
        int xor_all = 0;
        for (int i = 0; i < arr.size(); i ++) {
            xor_all ^= arr[i];
        }
        for (int i = 1; i <= n; i ++) {
            xor_all ^= i;
        }
        return xor_all;
    }
  public:
    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        // return approach_1(n, arr);
        
        // return approach_2(n, arr);
        
        return approach_3(n, arr);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends