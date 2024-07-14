// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && arr[i] == 0) i ++;
            while (i < j && arr[j] == 1) j --;
            swap(arr[i], arr[j]);
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
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
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends