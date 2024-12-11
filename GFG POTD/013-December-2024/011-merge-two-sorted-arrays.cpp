// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(M*log(M) + N*log(N))
    // SC : O(N)
    void brute(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int &num : b) pq.push(num);
        
        for (int i = 0; i < m; i ++) {
            if (!pq.empty() && a[i] > pq.top()) {
                int temp = a[i];
                a[i] = pq.top();
                pq.pop();
                pq.push(temp);
            }
        }
        
        for (int i = 0; i < n; i ++) {
            if (!pq.empty()) {
                b[i] = pq.top();
                pq.pop();
            }
        }
    }
    
    // TC : O(M*log(M) + N*log(N))
    // SC : O(1)
    void better(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (a[i] > b[j]) {
                swap(a[i --], b[j ++]);
            } else break;
        }
        sort(begin(a), end(a));
        sort(begin(b), end(b));
    }
    
    void swapIfGreater(vector<int>& a, vector<int>& b, int i, int j) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
        }
    }
    // TC : O(M*log(N))
    // SC : O(1)
    void optimal(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        int len = (m + n);
        int gap = (len / 2) + (len % 2);
        
        while (gap > 0) {
            int i = 0;
            int j = i + gap;
            while (j < len) {
                if (i < m && j >= m) {  // comparing arr1 & arr2
                    swapIfGreater(a, b, i, j - m);
                } else if (i >= m) {  // comparing arr2 & arr2
                    swapIfGreater(b, b, i - m, j - m);
                } else {    // comparing arr1 & arr1
                    swapIfGreater(a, a, i, j);
                }
                i ++, j ++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // brute(a, b);
        
        // better(a, b);
        
        return optimal(a, b);
    }
};


//{ Driver Code Starts.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends