// https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;
        for (int &num : arr) {
            xor_all ^= num;
        }
        
        // get the rightmost set bit : (x & (-x)) or (x & ~(x - 1))
        int mask = (xor_all & (-xor_all));
        int groupA = 0, groupB = 0;
        
        for (int &num : arr) {
            if (mask & num) {
                groupA ^= num;
            } else {
                groupB ^= num;
            }
        }
        if (groupB < groupA) swap(groupA, groupB);
        return {groupA, groupB};
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends