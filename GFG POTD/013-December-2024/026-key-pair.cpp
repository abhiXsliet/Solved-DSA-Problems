// https://www.geeksforgeeks.org/problems/key-pair5616/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    bool approach_1(vector<int>& arr, int target) {
        unordered_set<int> st;
        for (int &num : arr) {
            if (st.count(target - num)) 
                return true;
            st.insert(num);
        }
        return false;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    bool approach_2(vector<int>& arr, int target) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == target) 
                return true;
            else if (sum < target) {
                i ++;
            } else {
                j --;
            }
        }
        return false;
    }
  public:
    bool twoSum(vector<int>& arr, int target) {
        return approach_1(arr, target); // Hashmap
        return approach_2(arr, target); // sorting and two pointer
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends