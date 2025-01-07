// https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(log(N))
    // SC : O(1)
    int binarySearch(vector<int>& arr, int complement, int low, int high) {
        int ans = arr[low];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Update answer if we find a closer element
            if (abs(arr[mid] - complement) < abs(ans - complement)) {
                ans = arr[mid];
            }
            
            // If there is a tie, then we pick the larger value
            if (abs(arr[mid] - complement) == abs(ans - complement)) {
                ans = max(ans, arr[mid]);
            }
            
            if (arr[mid] == complement) {
                return arr[mid];
            } else if (arr[mid] < complement) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    // TC : O(N * N)
    // SC : O(1)
    vector<int> approach_1(vector<int>& arr, int tar) {
        int n = arr.size();
        int closeDiff = INT_MAX;
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int sum  = arr[i] + arr[j];
                int diff = abs(tar - sum);
                if (diff == closeDiff && abs(arr[i] - arr[j]) > abs(res[0] - res[1])) {
                    res = {min(arr[i], arr[j]), max(arr[i], arr[j])};
                } else if (diff < closeDiff) {
                    closeDiff = diff;
                    res = {min(arr[i], arr[j]), max(arr[i], arr[j])};
                } 
            }
        }
        return res;
    }
    
    // TC : O(N*log(N) + N*log(N))
    // SC : O(1)
    vector<int> approach_2(vector<int>& arr, int tar) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int closeDiff = INT_MAX;
        vector<int> res;
        for (int i = 0; i < n - 1; i ++) {
            int complement = abs(arr[i] - tar);
            int closestVal = binarySearch(arr, complement, i + 1, n - 1);
            int sum = arr[i] + closestVal;
            if (closeDiff > abs(tar - sum)) {
                closeDiff = abs(tar - sum);
                res = {min(arr[i], closestVal), max(arr[i], closestVal)};
            }
        }
        return res;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> approach_3(vector<int>& arr, int tar) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int closeDiff = INT_MAX;
        int i = 0, j = n - 1;
        vector<int> res;
        while (i < j) {
            int sum  = arr[i] + arr[j];
            int diff = abs(tar - sum);
            
            // Update the closest diff and result. 
            // Pairs with the maximum absolute difference are added first, so no explicit handling is needed.
            if (diff < closeDiff) {
                closeDiff = diff;
                res = {min(arr[i], arr[j]), max(arr[i], arr[j])};
            }
            
            if (sum > tar) j --;
            else i ++;
        }
        return res;
    }
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // return approach_1(arr, target);  // Brute 
        // return approach_2(arr, target);  // Better : Binary Search
        return approach_3(arr, target);  // Optimal : sorting + two pointer
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends