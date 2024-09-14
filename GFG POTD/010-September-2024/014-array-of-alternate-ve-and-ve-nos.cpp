// https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int> neg;
        vector<int> pos;
        for (int i = 0; i < n; i ++) {
            if (arr[i] < 0) {
                neg.push_back(arr[i]);
            } else {
                pos.push_back(arr[i]);
            }
        }
        
        int p1 = 0;
        int p2 = 0;
        bool f = 1;
        int i  = 0;
        
        while (p1 < pos.size() && p2 < neg.size()) {
            if (f) {
                arr[i ++] = pos[p1 ++];
            } else {
                arr[i ++] = neg[p2 ++];
            }
            f = !f;
        }
        while (p1 < pos.size()) {
            arr[i ++] = pos[p1 ++];
        }
        while (p2 < neg.size()) {
            arr[i ++] = neg[p2 ++];
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends