// https://www.geeksforgeeks.org/problems/pair-sum--120604/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int pairsum(vector<int> &arr) {
        int maxi1 = 0;
        int maxi2 = 0;
        for (int& num : arr) {
            if (num > maxi1) {
                maxi2 = maxi1;
                maxi1 = num;
            } else if (num > maxi2) {
                maxi2 = num;
            }
        }
        return (maxi1 + maxi2);
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
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends