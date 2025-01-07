// https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N*N)
    // SC : O(1)
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            int j = i + 1, k = n - 1;
            long sum = 0;
            while (j < k) {
                sum = arr[i] + arr[j] + arr[k];
                if (sum == target) {
                    
                    int ele1 = arr[j], ele2 = arr[k];
                    int cnt1 = 0, cnt2 = 0;
                    
                    while (j <= k && arr[j] == ele1) {
                        cnt1 ++, j ++;
                    }
                    while (j <= k && arr[k] == ele2) {
                        cnt2 ++, k --;
                    }
                    
                    if (ele1 == ele2) {
                        ans += (cnt1 * (cnt1 - 1)) / 2;
                    } else {
                        ans += (cnt1 * cnt2);
                    }
                    
                } else if (sum > target) k--;
                else j ++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends