// https://www.geeksforgeeks.org/problems/you-and-your-books/1



//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    long long max_Books(int arr[], int n, int k) {
        long long var_1 = 0, var_2 = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] <= k) 
                var_1 += arr[i];
            else {
                var_2 = max(var_1, var_2);
                var_1 = 0;
            }
        }
        return max(var_1, var_2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends