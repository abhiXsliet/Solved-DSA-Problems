// https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> mpp;
        mpp[0]    = 1;
        int sum   = 0;
        int count = 0;
        
        for (int &num : arr) {
            if (num == x) sum ++;
            else if (num == y) sum --;
            
            count += mpp[sum];
            mpp[sum] ++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends