// https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> mpp;
        int cntPairs = 0;
        for (int &num : arr) {
            cntPairs += mpp[target-num];
            mpp[num] ++;
        }
        return cntPairs;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends