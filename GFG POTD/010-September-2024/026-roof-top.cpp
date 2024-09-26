// https://www.geeksforgeeks.org/problems/roof-top-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int n = arr.size();
        int stepCnt  = 0;
        int counting = 0;
        for (int i = 1; i < n; i ++) {
            if (arr[i] > arr[i - 1]) {
                counting ++;
            } else {
                counting = 0;
            }
            stepCnt = max(stepCnt, counting);
        }
        return stepCnt;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends