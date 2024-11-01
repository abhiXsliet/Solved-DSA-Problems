// https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = 0;
        for (int i = 0; i < n/2; i++) {
            res -= (2 * arr[i]);
            res += (2 * arr[n - i - 1]);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends