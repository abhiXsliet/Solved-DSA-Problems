// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        while (i <= n - k && j < n) {
            mpp[arr[j]] ++;
            if (j - i + 1 == k) {
                result.push_back(mpp.size());
                mpp[arr[i]] --;
                if (mpp[arr[i]] == 0) 
                    mpp.erase(arr[i]);
                i ++;
            }
            j ++;
        }
        return result;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends