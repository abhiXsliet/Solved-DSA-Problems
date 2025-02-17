// https://www.geeksforgeeks.org/problems/k-largest-elements4206/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& arr, int k) {
        priority_queue<int> pq; // maxheap
        for (int num : arr) {
            pq.push(num);
        }
        vector<int> result;
        while (k --) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
    
    // TC : O(N*log(K))
    // SC : O(K)
    vector<int> approach_2(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<>> pq; // minHeap
        for (int num : arr) {
            if (pq.size() < k) {
                pq.push(num);
            } else {
                if (pq.top() < num) {
                    pq.push(num);
                    pq.pop();
                }
            }
        }

        vector<int> result(k);
        while (k) {
            result[k - 1] = pq.top();
            pq.pop();
            k --;
        }
        return result;
    }
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // return approach_1(arr, k);  // Not optimal
        return approach_2(arr, k);  // OPTIMAL
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
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends