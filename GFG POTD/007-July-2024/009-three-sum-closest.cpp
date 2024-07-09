// https://www.geeksforgeeks.org/problems/three-sum-closest/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value
class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        
        int n          = arr.size();
        int closestSum = INT_MAX;
        int minDiff    = INT_MAX;
        
        for (int i = 0; i < n - 2; ++i) {
            int low = i + 1;
            int high = n - 1;
            
            while (low < high) {
                int currentSum = arr[i] + arr[low] + arr[high];
                int currentDiff = abs(currentSum - target);
                
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                } else if (currentDiff == minDiff) {
                    closestSum = max(closestSum, currentSum);
                }
                
                if (currentSum < target) {
                    ++low;
                } else {
                    --high;
                }
            }
        }
        
        return closestSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends