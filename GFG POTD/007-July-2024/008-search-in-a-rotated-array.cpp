// https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(log(N)) Where N = Length of array
    // SC : O(1)
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if (arr[mid] == key) return mid;
            // check which part is sorted
            if (arr[low] <= arr[mid]) { // left part is sorted
                if (key >= arr[low] && key <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low  = mid + 1;
                }
            } else {    // right part is sorted
                if (key >= arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
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
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends