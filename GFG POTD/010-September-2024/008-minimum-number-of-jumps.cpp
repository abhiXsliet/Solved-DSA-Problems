// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    // TestCase :  1 3 5 3 4 2 6 7 6 || 1 3 5 3 4 0 0 0 0 0 0 || 0 3 5 3 4 0 0 0 0 0 0

    int minJumps(vector<int>& arr) {
        int n    = arr.size();
        int i    = 0;
        int jump = 0;
    
        while (i < n - 1) {
            int maxR = i + arr[i];
            if (maxR >= n - 1) 
                return jump + 1;  
    
            int maxiEl = 0;
            int maxIdx = i;
            // Check the range from i + 1 to maxR to find the next best jump
            for (int j = i + 1; j <= min(maxR, n - 1); j++) {
                int diff = min(maxR, n - 1) - j;
    
                if (maxiEl <= arr[j] - diff) {
                    maxiEl = arr[j] - diff;
                    maxIdx = j;  // Update to the best index for the next jump
                }
            }
            
            if (maxIdx == i)
                return -1;
    
            jump++; 
            i = maxIdx; 
        }
        return jump;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends