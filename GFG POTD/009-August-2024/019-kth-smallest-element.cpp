// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1



//{ Driver Code Starts
// Initial function template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>pq;
        
        for(int i = 0; i < arr.size(); i ++){
            pq.push(arr[i]);
            if (pq.size() > k) pq.pop();
        }
        
        return pq.top();
    }
};


//{ Driver Code Starts.
int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends