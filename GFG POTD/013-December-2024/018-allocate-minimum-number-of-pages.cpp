// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1




//{ Driver Code Starts
// Initial function template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    bool isPossible(vector<int>& arr, int tar, int k) {
        int sumPages = 0;
        int studentCnt = 1;
        for (int &page : arr) {
            if (sumPages + page <= tar) {
                sumPages += page;
            } else {
                studentCnt ++;
                if (studentCnt > k || page > tar)
                    return false;
                sumPages = page;
            }
        }
        return true;
    }
  public:
    // TC : O(N*log(N))
    // SC : O(1)
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) return -1;
        int sumOfPages = accumulate(begin(arr), end(arr), 0);
        int low  = arr[n - 1];   // to hold atleast one book
        int high = sumOfPages;  
        int ans  = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends