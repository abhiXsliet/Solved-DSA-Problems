// https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int getPivotIdx(int l, int r, vector<int>& arr, int key) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    
    int binarySearch(int l, int r, vector<int>& arr, int key) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int approach_1(vector<int>& arr, int key) {
        int n = arr.size();
        // pivot index is the index of the minimum element
        int pivot = getPivotIdx(0, n - 1, arr, key);    
        
        // Apply binary search on the left half of the pivot
        int idx = binarySearch(0, pivot - 1, arr, key);
        if (idx != -1) return idx;
        
        // Apply binary search on the right half of the pivot including it
        idx = binarySearch(pivot, n - 1, arr, key);
        return idx;
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int approach_2(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if (arr[mid] == key) return mid;
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
  public:
    int search(vector<int>& arr, int key) {
        // return approach_1(arr, key);    // apply binary search on left and right half 
    
        return approach_2(arr, key);    // find target in single iteration  
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
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends