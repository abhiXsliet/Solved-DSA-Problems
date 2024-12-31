// https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
  private:
    bool linearSearch(vector<int>& arr, int n, int tar) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == tar) return true;
        }
        return false;
    }
    
    // TC = O(N * N)
    // SC = O(1)
    int solve_brute(vector<int>& arr, int n) {
        int lengthLS = 1;
        // O(N)
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int curr_ele = arr[i];
            // O(N)
            while(linearSearch(arr, n, curr_ele)) {
                cnt++;
                curr_ele++;
            }
            lengthLS = max(lengthLS, cnt);
        }
        return lengthLS;
    }
    
    // TC = O(N*log(N))
    // SC = O(1)
    int solve_better(vector<int>& arr, int n) {
        sort (begin(arr), end(arr));
        
        int lengthLS = 1;
        int cnt = 0;
        int last_smaller = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int curr_ele = arr[i];
            
            if (last_smaller + 1 == curr_ele) {
                cnt++;
                last_smaller = curr_ele;
            }
            else if (last_smaller != curr_ele) {
                cnt = 1;
                last_smaller = curr_ele;
            }
            lengthLS = max(lengthLS, cnt);
        }
        return lengthLS;
    }
    
    // TC = O(N)
    // SC = O(N)
    int solve_optimal(vector<int>& arr, int n) {
        unordered_set<int> st (begin(arr), end(arr));
        
        int lengthLS = 1;
        for (int curr_ele : st) {
            int cnt = 0;
            // if last_ele of curr_ele is not found then
            if (st.find(curr_ele - 1) == st.end()) {
                // check if the curr_ele is making a chain of LCS?
                while (st.find(curr_ele) != st.end()) {
                    cnt++;
                    curr_ele++;
                }
            }
            lengthLS = max(lengthLS, cnt);
        }
        return lengthLS;
    }
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr)
    {   
        int N = arr.size();
        // return solve_brute(arr, N);
        
        // return solve_better(arr, N);
        
        return solve_optimal(arr, N);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends