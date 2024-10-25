// https://www.geeksforgeeks.org/problems/alternative-sorting1311/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& arr) {
        int n = arr.size();
        vector<int> vec = arr;
        sort(vec.rbegin(), vec.rend());
        int i = 0, j = n - 1, idx1 = 0, idx2 = 1;
        while (idx1 < n) {
            arr[idx1] = vec[i];
            arr[idx2] = vec[j];
            i ++, j --;
            idx1 += 2, idx2 += 2;
        }
        return arr;
    }
    
    // TC : O(N*log(N)) Inserting N elements into set
    // SC : O(K)        Where K = No. of Unique elements
    vector<int> approach_2(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        for (int &num : arr) {
            st.insert(num);
        }
        
        int idx = 0;
        for (auto it = st.rbegin(); it != st.rend(); it ++) {
            arr[idx] = *it;
            idx += 2;
            if (idx >= n) break;
        }
        
        idx = 1;
        for (int it : st) {
            arr[idx] = it;
            idx += 2;
            if (idx >= n) break;
        }
        return arr;
    }
  public:
    vector<int> alternateSort(vector<int>& arr) {
        // return approach_1(arr);
        
        return approach_2(arr);
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
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends