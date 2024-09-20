// https://www.geeksforgeeks.org/problems/facing-the-sun2126/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int n = height.size();
        int buildingCnt = 1;
        int maxHeight   = height[0];
        for (int i = 1; i < n; i ++) {
            if (height[i] > maxHeight) {
                buildingCnt += 1;
                maxHeight    = height[i];
            }
        }
        return buildingCnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends