// https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1




//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(log(N))
    // SC : O(1)
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (mid - 1 >= 0 && arr[mid - 1] == target) {
                return mid - 1;
            } else if (mid + 1 < n && arr[mid + 1] == target) {
                return mid + 1;
            } else if (arr[mid] < target){
                low = mid + 2;
            } else {
                high = mid - 2;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends