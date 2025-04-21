// https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &arr) {
        int n = arr.size();
        int xor_all = 0;
        for (int i = 1; i <= n + 1; i ++) {
            xor_all ^= i;
        }
        for (int &num : arr) {
            xor_all ^= num;
        }
        return xor_all;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        int missing = n + 1;
        for (int i = 0; i < n; i ++) {
            while (arr[i] != i + 1 && arr[i] - 1 < n) {
                swap(arr[i], arr[arr[i] - 1]);
            }
            if (arr[i] != i + 1) {
                missing = i + 1;
            }
        }
        return missing;
    }
  public:
    int missingNum(vector<int>& arr) {
        // return approach_1(arr); // using xor : double traversal of arr
        return approach_2(arr); // correct element at correct place
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends