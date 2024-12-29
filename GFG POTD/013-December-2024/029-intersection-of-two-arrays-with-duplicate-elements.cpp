// https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N + M) Where N = a.size() & M = b.size()
    // SC : O(N)
    vector<int> approach_1(vector<int>& a, vector<int>& b) {
        unordered_set<int> st (begin(a), end(a));
        vector<int> result;
        for (int i = 0; i < b.size(); i ++) {
            if (st.count(b[i])) {
                st.erase(b[i]);
                result.push_back(b[i]);
            } 
        }
        return result;
    }
    
    // TC : O(N*log(N) + M*log(M)) Where N = a.size() & M = b.size()
    // SC : O(1)
    vector<int> approach_2(vector<int>& a, vector<int>& b) {
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        vector<int> result;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i ++, j ++;
            } 
            else if (a[i] > b[j]) j ++;
            else if (a[i] < b[j]) i ++;
        }
        return result;
    }
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // return approach_1(a, b);
        return approach_2(a, b);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends