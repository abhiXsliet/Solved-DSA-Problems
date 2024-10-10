// https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mpp;
        int maxLen = 0;
        for (int i = 0; i < arr.size(); i ++) {
            if (mpp.count(arr[i]))
                maxLen = max(maxLen, i - mpp[arr[i]]);
            else 
                mpp[arr[i]] = i;
        }
        return maxLen;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends