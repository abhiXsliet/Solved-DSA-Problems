// https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(N^3)
    // SC : O(N^3)
    vector<vector<int>> approach_1(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                for (int k = j + 1; k < n; k ++) {
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        result.push_back({i, j, k});
                    }
                }
            }
        }
        return result;
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    vector<vector<int>> approach_2(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i ++) {
            vec[i] = {arr[i], i};
        }
        sort(begin(vec), end(vec));
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; i ++) {
            // if (i > 0 && vec[i].first == vec[i - 1].first) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = vec[i].first + vec[j].first + vec[k].first;
                if (sum == 0) {
                    vector<int> temp = {vec[i].second, vec[j].second, vec[k].second};
                    sort(begin(temp), end(temp));
                    result.push_back(temp);
                    j ++, k --;
                    // while (j < k && vec[j].first == vec[j - 1].first) j ++;
                    // while (j < k && vec[k].first == vec[k + 1].first) k --;
                } else if (sum > 0) 
                    k --;
                else 
                    j ++;
            }
        }
        return result;
    }
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // return approach_1(arr);  // Brute
        return approach_2(arr);  // Optimal but wrong answer on last testcase
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

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends