// https://www.geeksforgeeks.org/problems/aggressive-cows/1




//{ Driver Code Starts
// Initial function template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    bool isPossible(vector<int>& stalls, int tar, int k) {
        int countCows  = 1;
        int lastPlaced = stalls[0];
        for (int i = 1; i < stalls.size(); i ++) {
            if (lastPlaced + tar <= stalls[i]) {
                countCows ++;
                if (countCows >= k) return true;
                lastPlaced = stalls[i];
            }
        }
        return countCows >= k;
    }
  public:
    // TC : O(N*log(N))
    // SC : O(1)
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(begin(stalls), end(stalls));
        int low = 1, high = stalls[n - 1];
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(stalls, mid, k)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends