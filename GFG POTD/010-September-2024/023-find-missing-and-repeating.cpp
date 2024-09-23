// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> brute(vector<int>& arr, int n) {
        vector<int> result;
        
        sort(begin(arr), end(arr));
        
        unordered_set<int> st;
        for (int& num : arr) {
            st.insert(num);
        }
        
        int duplicate = 0;
        int missingNo = 1;
        
        for (int i = 0; i < n-1; i++) {
            if (arr[i] == arr[i+1]) {
                result.push_back(arr[i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (st.find(missingNo) == st.end()) {
                result.push_back(missingNo);
                if (result.size() == 2) return result;
            }
            else {
                missingNo ++;
            }
        }
        
        return {};
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> better(vector<int>& arr, int n) {
        vector<int> result;
        
        unordered_map<int, int> mpp;
        for (int& num : arr) {
            mpp[num]++;
        }
        
        for (auto& val : mpp) {
            if (val.second == 2) {
                result.push_back(val.first);
            }
        }
        
        int missingNo = 1;
        for (int i = 0; i < n; i++) {
            if (mpp.find(missingNo) == mpp.end()) {
                result.push_back(missingNo);
                if (result.size() == 2) return result;
            }
            else {
                missingNo ++;
            }
        }
        
        return {};
    }
    

    // TC : O(N)
    // SC : O(1)
    vector<int> optimal(vector<int>& arr, int n) {
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            // Swap elements till it not reached to its correct indexes
            if (arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
                i--;
            }
        }
        
        // find the duplicate and missing number
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                result.push_back(arr[i]);   // duplicate number
                result.push_back(i + 1);    // missing number
                break;
            }
        }
        
        return result;
    }
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        // return brute(arr, n);
        
        // return better(arr, n);
        
        return optimal(arr, n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends