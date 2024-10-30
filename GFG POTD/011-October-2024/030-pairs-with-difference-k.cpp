// https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution { 
  private:
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
        int i = 0, j = 0, cntPairs = 0, n = arr.size();
        while (j < n) {
            if (arr[j] - arr[i] > k) i ++;
            else if (arr[j] - arr[i] < k) j ++;
            else {
                int el1 = arr[i], el2 = arr[j];
                int cn1 = 0, cn2 = 0;
                while (j < n && el2 == arr[j]) {
                    cn2 ++;
                    j ++;
                }
                while (el1 == arr[i]) {
                    cn1 ++;
                    i ++;
                }
                
                // If both the elements are same, then count of
                // pairs = the number of ways to choose 2 
                // elements among cnt1 elements
                if (el1 == el2) {
                    cntPairs += (cn1 * (cn1 - 1)) / 2;
                } else { 
                // count of pairs = product of the count of both elements
                    cntPairs += (cn1 * cn2);
                }
            }
        }
        return cntPairs;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        int countPairs = 0;
        for (int &num : arr) {
            if (mpp.count(num + k)) {
                countPairs += mpp[num + k];
            }
            if (mpp.count(num - k)) {
                countPairs += mpp[num - k];
            }
            mpp[num] ++;
        }
        return countPairs;
    }
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        return approach_1(arr, k);  // Sort and use 2-pointer
        // return approach_2(arr, k);  // HashMap : add freq of (num + k) & (num - k)
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
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends