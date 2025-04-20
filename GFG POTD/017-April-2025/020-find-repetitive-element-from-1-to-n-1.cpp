// https://www.geeksforgeeks.org/problems/find-repetitive-element-from-1-to-n-1/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            while (arr[i] != i + 1) {
                if (arr[i] == arr[arr[i] - 1])
                    return arr[i];
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends