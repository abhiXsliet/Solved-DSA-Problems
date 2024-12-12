// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1




//{ Driver Code Starts
// Initial function template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int bsLower(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int lower_bound = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                lower_bound = mid;
                high = mid - 1;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return lower_bound;
    }
    
    int bsUpper(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int lower_bound = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                lower_bound = mid;
                low = mid + 1;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return lower_bound;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int>& arr, int target) {
        int cntTarget = 0;
        for (int &num : arr) {
            if (num == target) 
                cntTarget ++;
        }
        return cntTarget;
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int approach_2(vector<int>& arr, int target) {
        int lower_bound = bsLower(arr, target);
        int upper_bound = bsUpper(arr, target);
        if (lower_bound == -1 && upper_bound == -1) 
            return 0;
            
        return (upper_bound - lower_bound + 1);
    }
  public:
    int countFreq(vector<int>& arr, int target) {
        // return approach_1(arr, target);
        
        return approach_2(arr, target);
    }
};


//{ Driver Code Starts.
int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends