// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
typedef long long int ll;
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<ll> prefix(n), suffix(n);
        
        ll prodL = 1, prodR = 1;
        
        for (int i = 0; i < n; i ++) {
            prodL *= nums[i];
            prodR *= nums[n - i - 1];
            prefix[i]         = prodL;
            suffix[n - i - 1] = prodR;
        }
        
        vector<ll> result(n);
        
        for (int i = 0; i < n; i ++) {
            ll valL   = (i - 1) >= 0 ? prefix[i - 1] : 1;
            ll valR   = (i + 1)  < n ? suffix[i + 1] : 1;
            result[i] = valL * valR;
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends