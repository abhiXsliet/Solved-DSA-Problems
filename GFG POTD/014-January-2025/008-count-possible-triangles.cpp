// https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N^3)
    // SC : O(1)
    int brute(vector<int>& arr) {
        int n = arr.size();
        int cntTrngle = 0;
        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                for (int k = j + 1; k < n; k ++) {
                    if (arr[i] + arr[j] > arr[k] && 
                        arr[i] + arr[k] > arr[j] && 
                        arr[j] + arr[k] > arr[i]) {
                        cntTrngle ++;
                    }
                }
            }
        }
        return cntTrngle;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int optimal(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int cntTrngle = 0;
        for (int i = 0; i < n - 2; i ++) {
            int k = n - 1;
            int j = k - 1;
            while (i < j) {
                while (i < j && arr[i] + arr[j] > arr[k]) {
                    cntTrngle ++;
                    j --;
                    if (j == i) {
                        k --;
                        j = k - 1;
                    }
                }
                if (arr[i] + arr[j] <= arr[k]) {
                    k --;
                    j = k - 1;
                } 
            }
        }
        return cntTrngle;
    }
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // return brute(arr);
        
        return optimal(arr);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
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
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends