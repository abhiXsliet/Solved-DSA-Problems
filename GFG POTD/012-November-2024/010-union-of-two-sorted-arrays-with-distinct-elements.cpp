// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (a[i] == b[j]) {
                res.push_back(a[i]);
                i ++, j ++;
            } else if (a[i] > b[j]) {
                res.push_back(b[j]);
                j ++;
            } else {
                res.push_back(a[i]);
                i ++;
            }
        }
        while (i < m) {
            res.push_back(a[i]);
            i ++;
        }
        while (j < n) {
            res.push_back(b[j]);
            j ++;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends