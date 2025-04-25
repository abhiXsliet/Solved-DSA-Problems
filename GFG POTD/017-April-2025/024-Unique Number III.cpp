// https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &arr) {
        int n = arr.size();
        
        int unique = 0;
        for (int i = 0; i < 32; i ++) {
            int cntZeros = 0, cntOnes = 0;
            for (int &num : arr) {
                if (1 & (num >> i)) {
                    cntOnes += 1;
                } else {
                    cntZeros += 1;
                }
            }
            if (cntOnes % 3) {
                unique |= (1 << i);
            }
        }
        return unique;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        
        int ones = 0, twos = 0;
        for (int &num : arr) {
            ones = (ones ^ num) & (~twos);  // add in ones if not present in twos
            twos = (twos ^ num) & (~ones);  // add in twos if present in ones and remove from ones
        }
        return ones;
    }
  public:
    int getSingle(vector<int> &arr) {
        // return approach_1(arr); // Iterate of all 32-bits of each no.
        
        return approach_2(arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends