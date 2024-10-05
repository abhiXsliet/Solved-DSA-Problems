// https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    typedef long long ll;
    
    // TC : O(N * SUM) Where N = arr.size()
    // SC : O(SUM)     Where SUM = total sum of array elements
    ll approach_1(vector<int>& arr) {
        ll total = accumulate(begin(arr), end(arr), 0LL);
        vector<bool> dp(total + 1, 0);
        dp[0] = 1;  
        
        for (int i = 0; i < arr.size(); i ++) {
            for (int j = total; j >= arr[i]; j --) {
                if (dp[j - arr[i]]) {
                    dp[j] = 1;
                }
            }
        }
        
        for (int i = 1; i <= total; i ++) {
            if (!dp[i]) {
                return i;
            }
        }
        return (total + 1);
    }
    
    // TC : O(N)
    // SC : O(1)
    ll approach_2(vector<int>& arr) {
        ll currSmallest = 1;
        for (int& num : arr) {
            if (currSmallest >= num) {
                currSmallest += num;
            }
        }
        return currSmallest;
    }
  public:
    long long findSmallest(vector<int> &arr) {
        // return approach_1(arr); // DP
    
        return approach_2(arr); // Assume and check if assumption >= arr[i] then increase assumption += arr[i]
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends