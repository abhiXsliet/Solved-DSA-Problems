// https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1




//{ Driver Code Starts
// Initial function template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N*d) ~= O(N^2)
    // SC : O(1)
    void brute(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;
        while (d --) {
            int temp = arr[0];
            for (int i = 1; i < n; i ++) {
                arr[i - 1] = arr[i];
            }
            arr[n - 1] = temp;
        }
    }
    
    // TC : O(N)
    // SC : O(1)
    void optimal(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;
        // 1. reverse the whole array
        reverse(begin(arr), end(arr));
        // 2. revere the first n - d elements
        reverse(begin(arr), begin(arr) + (n - d));
        // 3. reverse the rest elements
        reverse(begin(arr) + (n - d), end(arr));
    }
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // brute(arr, d);
        optimal(arr, d);
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
        // calling rotateArr() function
        ob.rotateArr(arr, d);

        // printing the elements of the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends