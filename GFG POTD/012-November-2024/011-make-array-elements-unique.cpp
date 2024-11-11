// https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(N * Log(N))
    // SC : O(N)
    int approach_1(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int &num : arr) {
            pq.push(num);
        }
        
        int cntInc = 0;
        while (!pq.empty()) {
            int el = pq.top();
            pq.pop();
            
            if (pq.empty()) break;
            if (el == pq.top()) {
                pq.push(el + 1);
                cntInc ++;
            }
        }
        return cntInc;
    }
    
    // TC : O(N * Log(N))
    // SC : O(1)
    int approach_2(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int cntInc = 0;
        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i] <= arr[i - 1]) {
                cntInc += (arr[i - 1] - arr[i] + 1);
                arr[i]  = arr[i - 1] + 1;
            }
        }
        return cntInc;
    }
  public:
    int minIncrements(vector<int>& arr) {
        // return approach_1(arr); // MinHeap : TLE
        
        return approach_2(arr);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends