// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxL(n, arr[0]);
        vector<int> maxR(n, arr[n-1]);
        for (int i = 1; i < n; i ++) {
            maxL[i]     = max(maxL[i - 1], arr[i]);
            maxR[n-i-1] = max(maxR[n - i], arr[n-i-1]);
        }
        int maxWater = 0;
        for (int i = 1; i < n; i ++) {
            int val   = min(maxL[i], maxR[i]) - arr[i];
            maxWater += val < 0 ? 0 : val;
        }
        return maxWater;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& arr) {
        int n = arr.size();
        int maxL = arr[0], maxR = arr[n - 1];
        int maxWater = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (arr[left] < arr[right]) {
                maxWater += min(0, maxL - arr[left]);
                maxL = max(maxL, arr[left]);
                left ++;
            } else {
                maxWater += min(0, maxR - arr[right]);
                maxR = max(maxR, arr[right]);
                right --;
            }
        }
        return maxWater;
    }
  public:
    int maxWater(vector<int> &arr) {
        // return approach_1(arr);
        
        return approach_1(arr);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends