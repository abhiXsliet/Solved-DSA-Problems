// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    typedef pair<int, int> P;
    
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<P> pq;
        vector<int> result(n - k + 1);
        int i = 0, j = 0;
        while (j < n) {
            pq.push({arr[j], j});
            while (!pq.empty() && pq.top().second < i) {
                pq.pop();
            }
            if (j - i + 1 == k) {
                result[i] = pq.top().first;
                i ++;
            }
            j ++;
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(K)
    vector<int> approach_2(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result(n - k + 1);
        list<int> li;
        int i = 0, j = 0;
        while (j < n) {
            while (!li.empty() && arr[li.back()] < arr[j]) {
                li.pop_back();
            }
            
            li.push_back(j);

            if (j - i + 1 == k) {
                if (li.front() < i) li.pop_front(); // list front indices is < i then pop it
                result[i] = arr[li.front()];
                i ++;
            }
            j ++;
        }
        return result;
    }
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // return approach_1(arr, k);  // using max-heap {val, index} : pop from pq until top element-idx < i
        return approach_2(arr, k);  // Using K-sized list & linear time 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends