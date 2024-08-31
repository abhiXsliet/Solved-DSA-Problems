// https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}
// } Driver Code Ends

// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]
class Solution {
  private:
    vector<int> findSequence(vector<int> &arr, vector<int> &ans, int n, int i) {
        // Base case: if the sequence of 3 elements is found
        if (ans.size() == 3) {
            return ans;
        }
        
        // Recursive case: explore elements to find valid subsequence
        for (int j = i; j < n; j++) {
            if (ans.empty() || ans.back() < arr[j]) {
                ans.push_back(arr[j]);
                
                // Recursively call to find the next element
                vector<int> result = findSequence(arr, ans, n, j + 1);
                
                // If a valid sequence of 3 is found, return it
                if (!result.empty()) 
                    return result;
                
                // Backtrack and try the next possibility
                ans.pop_back();
            }
        }

        // If no valid sequence is found, return an empty vector
        return {};
    }
    
    // TC : O(N^3)
    // SC : O(1)
    vector<int> approach_1(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int firstEl = arr[i];
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > firstEl) {
                    int secondEl = arr[j];
                    for (int k = j + 1; k < n; k++) {
                        if (arr[k] > secondEl) {
                            // We have found the subsequence arr[i], arr[j], arr[k]
                            return {firstEl, secondEl, arr[k]};
                        }
                    }
                }
            }
        }
        return {}; // If no such subsequence is found

    }
    
    // TC : O(N^3)
    // SC : O(N)
    vector<int> approach_2(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        return findSequence(arr, ans, n, 0);
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_3(vector<int>& arr) {
        int n = arr.size();
        vector<int> mini(n, arr[0]);
        vector<int> maxi(n, arr[n - 1]);
        
        for (int i = 1; i < n; i ++) {
            mini[i]         = min(arr[i - 1], mini[i - 1]);
            maxi[n - i - 1] = max(arr[n - i - 1], maxi[n - i]);
        }
        
        for (int i = 1; i < n - 1; i ++) {
            if (mini[i] < arr[i] && arr[i] < maxi[i]) {
                return {mini[i], arr[i], maxi[i]};
            }
        }
        return {};
    }
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // return approach_1(arr); // Brute
        
        // return approach_2(arr); // Brute Recursive
        
        return approach_3(arr);     
    }
};



//{ Driver Code Starts.
// Driver program to test above function
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
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends