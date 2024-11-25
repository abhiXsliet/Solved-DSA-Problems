// https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function template for C++
class Solution{
private:
    typedef long long ll;
    
    // TC = O(N * N * N)
    // SC = O(1)
    ll solve_brute(vector<int>& arr, int n) {
        ll maxProd = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ll prod = 1;
                for (int k = i; k <= j; k++) {
                    prod *= arr[k];
                }
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
    
    // TC = O(N * N)
    // SC = O(1)
    ll solve_better(vector<int>& arr, int n) {
        ll maxProd = INT_MIN;
        for (int i = 0; i < n; i++) {
            ll prod = 1;
            for (int j = i; j < n; j++) {
                prod   *= arr[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
    
    // TC = O(N)
    // SC = O(1)
    // Intution -> odd/even no. of -ves, zero divides the array into segments
    ll solve_optimal_1(vector<int>& arr, int n) {
        ll maxProd = INT_MIN;
        ll prefix = 1;
        ll suffix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            
            prefix *= arr[i];
            suffix *= arr[n - i - 1];
            
            maxProd = max(maxProd, max(prefix, suffix));
        }
        return maxProd;
    }
    
    // TC = O(N)
    // SC = O(1)
    // Intution -> Kadanes modification
    ll solve_optimal_2(vector<int>& arr, int n) {
        ll maxProd = arr[0];
        ll prod1   = arr[0];
        ll prod2   = arr[0];
        for (int i = 1; i < n; i++) {
            ll temp = max({(ll)arr[i], (ll)prod1*arr[i], (ll)prod2*arr[i]});
            prod2 = min({(ll)arr[i], (ll)prod1*arr[i], (ll)prod2*arr[i]});
            prod1 = temp;
            
            maxProd = max(maxProd, prod1);
        }
        return maxProd;
    }
public:
	// Function to find maximum product subarray
	ll maxProduct(vector<int> arr) {
	    int n = arr.size();
	   // return solve_brute(arr, n);
	   
	   //return solve_better(arr, n);
	   
	   //return solve_optimal_1(arr, n);
	   
	   return solve_optimal_2(arr, n);
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends