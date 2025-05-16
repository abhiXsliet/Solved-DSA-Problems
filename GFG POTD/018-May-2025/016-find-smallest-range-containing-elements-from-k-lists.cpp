// https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N * K)
    // SC : O(K)
    vector<int> approach_1(vector<vector<int>> &arr) {
        int k = arr.size();
        int dist = INT_MAX;
        vector<int> result(2, INT_MIN);
        vector<int> store(k, 0);    // initially every element is pointing to 0th index
        while (true) {
            int minIdx = -1, minEle = INT_MAX, maxEle = INT_MIN;
            
            for (int i = 0; i < k; i ++) {
                int element = arr[i][store[i]];
                if (element < minEle) {
                    minEle = element;
                    minIdx = i;
                }
                maxEle = max(maxEle, element);
            }
            
            if (dist > (maxEle - minEle)) {
                dist = (maxEle - minEle);
                result[0] = minEle;
                result[1] = maxEle;
            }
            
            // shorten the range by moving the minEleIdx
            int nextIdx = store[minIdx] + 1;
            
            if (nextIdx >= arr[minIdx].size()) 
                break;
                
            store[minIdx] = nextIdx;
        }
        return result;
    }
    
    // TC : O(N * log(K))
    // SC : O(K)
    vector<int> approach_2(vector<vector<int>> &arr) {
        int k = arr.size();
        vector<int> result(2, INT_MIN);
        int dist = INT_MAX;
        
        // {element, listIdx, idx}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxEle = INT_MIN;
        for (int i = 0; i < k; i ++) {
            pq.push({arr[i][0], i, 0});
            maxEle = max(maxEle, arr[i][0]);
        }
        
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            int minEle = curr[0], listIdx = curr[1], idx = curr[2];
            
            if (dist > (maxEle - minEle)) {
                dist = (maxEle - minEle);
                result[0] = minEle;
                result[1] = maxEle;
            }
            
            // decrease the range for minimum idx
            if (idx + 1 < arr[listIdx].size()) {
                int nextEle = arr[listIdx][idx + 1];
                pq.push({nextEle, listIdx, idx + 1});
                maxEle = max(maxEle, nextEle);
            } else {
                break;
            }
        }
        return result;
    }
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // return approach_1(arr);
        return approach_2(arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends